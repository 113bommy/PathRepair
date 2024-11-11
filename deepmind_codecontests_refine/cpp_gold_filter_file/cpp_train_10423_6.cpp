#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;
int a[N];
int pos[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = '#' + s;
  vector<int> cnt, poss, pose;
  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'G')
      c++;
    else {
      if (c) cnt.push_back(c);
      c = 0;
    }
  }
  if (c) cnt.push_back(c);
  if (cnt.size() == 0)
    cout << "0" << '\n';
  else if (cnt.size() == 1)
    cout << cnt[0] << '\n';
  else if (cnt.size() == 2) {
    int sp = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'G') {
        sp = i;
        break;
      }
    }
    if (s[cnt[0] + sp - 1] != s[cnt[0] + sp + 1])
      cout << max(cnt[0], cnt[1]) + 1 << '\n';
    else
      cout << cnt[0] + cnt[1] << '\n';
  } else {
    int mx = *max_element(cnt.begin(), cnt.end());
    mx++;
    int sp = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'G') {
        sp = i;
        break;
      }
    }
    pose.push_back(sp + cnt[0] - 1);
    poss.push_back(sp);
    for (int i = pose[0] + 1; i < n; i++) {
      if (s[i] == 'S' && s[i + 1] == 'G') {
        poss.push_back(i + 1);
        pose.push_back(i + cnt[poss.size() - 1]);
      }
    }
    for (int i = 1; i < poss.size(); i++) {
      if (poss[i] - pose[i - 1] == 2) mx = max(mx, cnt[i] + cnt[i - 1] + 1);
    }
    cout << mx << '\n';
  }
  return 0;
}
