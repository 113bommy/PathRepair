#include <bits/stdc++.h>
static int xd = 0;
using namespace std;
template <class num>
inline void rd(num &x) {
  char c;
  while (isspace(c = getchar()))
    ;
  bool neg = false;
  if (!isdigit(c))
    neg = (c == '-'), x = 0;
  else
    x = c - '0';
  while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
  if (neg) x = -x;
}
int calc(string s) {
  int sum = 0;
  int n = s.size();
  cout << s << endl;
  s = s + s;
  for (int i = 0; i < n; i++) {
    bool valid = true;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      int c = s[i + j];
      if (c == ')' and !cnt) {
        valid = false;
        break;
      }
      if (c == ')')
        cnt--;
      else
        cnt++;
    }
    valid = valid and !cnt;
    if (valid) cout << s.substr(i, n) << endl;
    sum += valid;
  }
  return sum;
}
int v[1123456];
map<int, vector<int> > pos;
int main(void) {
  int n;
  rd(n);
  string s;
  cin >> s;
  int cnt = 0;
  int c[2] = {0};
  int mini = 0;
  for (int i = 0; i < n; i++) {
    c[s[i] == ')']++;
    cnt += s[i] == '(';
    cnt -= s[i] == ')';
    v[i] = cnt;
    mini = min(mini, cnt);
    pos[cnt].push_back(i);
  }
  if (c[0] != c[1]) {
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  n--;
  pair<int, int> lr = make_pair(0, -1);
  int ans = pos[mini].size();
  {
    int x = mini - 1;
    vector<int> forb;
    forb.push_back(-1);
    for (auto f : pos[x + 1]) forb.push_back(f);
    forb.push_back(n);
    int best = 0;
    pair<int, int> llrr = make_pair(0, -1);
    for (int i = 1; i < forb.size(); i++) {
      int l = forb[i - 1] + 1;
      int r = forb[i] - 1;
      if (l > r) continue;
      int k1 = lower_bound(pos[x + 2].begin(), pos[x + 2].end(), l) -
               pos[x + 2].begin();
      int k2 = upper_bound(pos[x + 2].begin(), pos[x + 2].end(), r) -
               pos[x + 2].begin();
      if (k2 - k1 > best) llrr = make_pair(l, r);
      best = max(best, k2 - k1);
    }
    if (best + int(pos[x].size()) > ans) lr = llrr;
    ans = max(ans, best + int(pos[x].size()));
  }
  {
    int x = mini;
    vector<int> forb;
    forb.push_back(-1);
    for (auto f : pos[x + 1]) forb.push_back(f);
    for (auto f : pos[x]) forb.push_back(f);
    forb.push_back(n);
    sort(begin(forb), end(forb));
    pair<int, int> llrr = make_pair(0, -1);
    int best = 0;
    for (int i = 1; i < forb.size(); i++) {
      int l = forb[i - 1] + 1;
      int r = forb[i] - 1;
      if (l > r) continue;
      int k1 = lower_bound(pos[x + 2].begin(), pos[x + 2].end(), l) -
               pos[x + 2].begin();
      int k2 = upper_bound(pos[x + 2].begin(), pos[x + 2].end(), r) -
               pos[x + 2].begin();
      if (k2 - k1 > best) llrr = make_pair(l, r);
      best = max(best, k2 - k1);
    }
    if (best + int(pos[x].size()) > ans) lr = llrr;
    ans = max(ans, best + int(pos[x].size()));
  }
  {
    int x = mini + 1;
    int l = pos[mini][0];
    int r = pos[mini].back();
    int best = pos[mini + 1].size();
    for (int i = l; i <= r; i++)
      if (v[i] == mini + 1) best--;
    if (best > ans) {
      lr = make_pair(l, r);
    }
    ans = max(ans, best);
  }
  {
    int x = mini + 2;
    int l = INT_MAX, r = INT_MIN;
    for (int i = 0; i <= n; i++)
      if (v[i] == mini or v[i] == mini + 1) {
        l = min(l, i);
        r = max(r, i);
      }
    int best = pos[mini + 2].size();
    for (int i = l; i <= r; i++) {
      if (v[i] == mini + 2) best--;
      if (v[i] == mini) best++;
    }
    if (best > ans) {
      lr = make_pair(l, r);
    }
    ans = max(ans, best);
  }
  cout << ans << endl;
  cout << lr.first + 1 << " " << lr.second + 2 << endl;
  swap(s[lr.first], s[lr.second + 1]);
  return 0;
}
