#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
bool check(int k) {
  int ans_a = 0, ans_b = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == 'a')
      ans_a++;
    else
      ans_b++;
  }
  if (ans_a <= m || ans_b <= m) return true;
  for (int i = k; i < n; i++) {
    if (s[i] == 'a')
      ans_a++;
    else
      ans_b++;
    if (s[i - k] == 'a')
      ans_a--;
    else
      ans_b--;
  }
  if (ans_a <= m || ans_b <= m) return true;
  return false;
}
int main() {
  cin >> n >> m;
  cin >> s;
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << r << endl;
  return 0;
}
