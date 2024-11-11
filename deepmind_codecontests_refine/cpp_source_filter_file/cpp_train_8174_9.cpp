#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
long long gas[MAXN];
long long pref[MAXN];
long long suf[MAXN];
void solve(int* ans, long long* a, long long* b, int n) {
  int j = 1;
  gas[0] = 0;
  for (int i = (int)0; i < (int)n; i++) {
    gas[j] = gas[j - 1] + a[i];
    j++;
    gas[j] = gas[j - 1] - b[i];
    j++;
  }
  pref[0] = gas[0];
  for (int i = (int)1; i < (int)j; i++) pref[i] = min(pref[i - 1], gas[i]);
  suf[j - 1] = gas[j - 1];
  for (int i = j - 2; i >= 0; i--) suf[j] = min(suf[j + 1], gas[j]);
  if (pref[j - 1] >= 0) ans[0] = 1;
  for (int k = 2, id = 1; id < n; id++, k += 2) {
    int mini_fst = suf[k] - gas[k];
    int mini_snd = gas[j - 1] - gas[k] + pref[k - 1];
    if (mini_fst >= 0 and mini_snd >= 0) ans[id] = 1;
  }
}
long long a[MAXN], b[MAXN];
long long a1[MAXN], b1[MAXN];
int is_pos[MAXN];
int is_pos1[MAXN];
int main() {
  int n;
  cin >> n;
  for (int i = (int)0; i < (int)n; i++) cin >> a[i];
  for (int i = (int)0; i < (int)n; i++) cin >> b[i];
  for (int i = (int)0; i < (int)n; i++) a1[i] = a[n - 1 - i];
  for (int i = (int)0; i < (int)n - 1; i++) b1[i] = b[n - 2 - i];
  b1[n - 1] = b[n - 1];
  solve(is_pos, a, b, n);
  solve(is_pos1, a1, b1, n);
  vector<int> v;
  for (int i = (int)0; i < (int)n; i++)
    if (is_pos[i] or is_pos1[n - 1 - i]) {
      v.push_back(i);
    }
  cout << v.size() << endl;
  for (int i = (int)0; i < (int)v.size(); i++) {
    if (i) cout << " ";
    cout << v[i] + 1;
  }
  cout << endl;
  return 0;
}
