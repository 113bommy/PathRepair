#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
const long double PI = 2 * acos(0.0);
const vector<long long int> dx = {1, -1, 0, 0};
const vector<long long int> dy = {0, 0, 1, -1};
vector<long long int> ga(long long int n, bool oneIndexed = false) {
  vector<long long int> a;
  if (oneIndexed) a.push_back(0ll);
  for (long long int i = 0; i < n; i++) {
    long long int p;
    cin >> p;
    a.push_back(p);
  }
  return move(a);
}
vector<unsigned long long int> gau(unsigned long long int n,
                                   bool oneIndexed = false) {
  vector<unsigned long long int> a;
  if (oneIndexed) a.push_back(0llu);
  for (unsigned long long int i = 0; i < n; i++) {
    unsigned long long int p;
    cin >> p;
    a.push_back(p);
  }
  return move(a);
}
vector<string> gas(unsigned long long int n, bool oneIndexed = false) {
  vector<string> a;
  if (oneIndexed) a.push_back("");
  for (unsigned long long int i = 0; i < n; i++) {
    string p;
    cin >> p;
    a.push_back(p);
  }
  return move(a);
}
template <typename T, typename A>
void pa(vector<T, A> const &a, long long int begin = 0,
        long long int end = -1) {
  if (end == -1) end = (long long int)a.size() - 1;
  for (long long int i = begin; i <= end; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
template <typename T, typename A>
void papair(vector<T, A> const &a, long long int begin = 0,
            long long int end = -1) {
  if (end == -1) end = (long long int)a.size() - 1;
  for (long long int i = begin; i <= end; i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
  cout << "\n";
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
void yesno(int f) {
  if (f)
    yes();
  else
    no();
}
void solve() {
  string s;
  cin >> s;
  long long int n = (long long int)s.size();
  long long int ra = -1, rb = -1, ma = -1, mb = -1;
  vector<long long int> sum(n);
  sum[0] = s[0] == '[';
  for (long long int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + (s[i] == '[');
  }
  long long int start = -1, len = 0;
  stack<pair<char, long long int>> st;
  vector<bool> vis(n, false);
  for (long long int i = 0; i < n; i++) {
    switch (s[i]) {
      case '(':
      case '[':
        st.push({s[i], i});
        break;
      case ')':
      case ']':
        if (!st.empty() && ((s[i] == ')' && st.top().first == '(') ||
                            (s[i] == ']' && st.top().first == '['))) {
          vis[st.top().second] = true;
          vis[i] = true;
          st.pop();
        } else {
          ra = rb = -1;
          while (!st.empty()) st.pop();
        }
    }
  }
  for (long long int i = 0; i < n;) {
    long long int j = i;
    if (!vis[i]) {
      i++;
      continue;
    }
    while (j < n - 1 && vis[j + 1]) {
      j++;
    }
    if (ma == -1 ||
        sum[mb] - (ma ? sum[ma - 1] : 0) > sum[j] - (i ? sum[i - 1] : 0)) {
      ma = i;
      mb = j;
    }
    i = j + 1;
  }
  if (ma == -1)
    cout << 0;
  else {
    cout << sum[mb] - (ma ? sum[ma - 1] : 0) << "\n";
    for (long long int i = ma; i <= mb; i++) {
      cout << s[i];
    }
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
