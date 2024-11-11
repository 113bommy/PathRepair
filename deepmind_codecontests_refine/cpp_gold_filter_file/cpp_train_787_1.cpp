#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9 + 7;
const long long MOD = 1e9 + 7;
const long long P = 29;
const long double EPS = 1e-9;
const long double PI = acos(-1);
const int N = 1e6 + 10;
const int M = 1e3 + 10;
char ans[N];
int cnt1[N], cnt2[N];
bool ok(int *a, int *b) {
  int al = INF, br = -INF;
  for (int i = 0; i < 26; ++i)
    if (a[i]) al = min(al, i);
  for (int i = 0; i < 26; ++i)
    if (b[i]) br = i;
  return al >= br;
}
int lft(int *a) {
  for (int i = 0; i < 26; ++i)
    if (a[i]) return i;
}
int rgt(int *a) {
  for (int i = 25; i >= 0; i--)
    if (a[i]) return i;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s1, s2;
  cin >> s1 >> s2;
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  reverse(s2.begin(), s2.end());
  int n = s1.size();
  s1.resize((n + 1) / 2);
  s2.resize(n / 2);
  for (int i = 0; i < s1.size(); ++i) cnt1[s1[i] - 'a']++;
  for (int i = 0; i < s2.size(); ++i) cnt2[s2[i] - 'a']++;
  int curl = 0, curr = n - 1;
  int step = 0;
  while (curl <= curr) {
    if (!step) {
      if (ok(cnt1, cnt2)) {
        int t = rgt(cnt1);
        ans[curr] = (char)(t + 'a');
        curr--;
        cnt1[t]--;
      } else {
        int t = lft(cnt1);
        ans[curl] = (char)(t + 'a');
        curl++;
        cnt1[t]--;
      }
    } else {
      if (ok(cnt1, cnt2)) {
        int t = lft(cnt2);
        ans[curr] = (char)(t + 'a');
        curr--;
        cnt2[t]--;
      } else {
        int t = rgt(cnt2);
        ans[curl] = (char)(t + 'a');
        curl++;
        cnt2[t]--;
      }
    }
    step = !step;
  }
  for (int i = 0; i < n; ++i) cout << ans[i];
}
