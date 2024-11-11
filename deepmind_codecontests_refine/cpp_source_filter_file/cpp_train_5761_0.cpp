#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  int psum[n], no_of_p_start_at[n], no_of_p_end_at[n];
  memset(psum, 0, sizeof(psum));
  memset(no_of_p_start_at, 0, sizeof(no_of_p_start_at));
  memset(no_of_p_end_at, 0, sizeof(no_of_p_end_at));
  for (int i = 0; i < n; i++) {
    int j = 0;
    while ((i - j) >= 0 && (i + j) < n) {
      if (s[i - j] == s[i + j]) {
        no_of_p_start_at[i - j]++;
        no_of_p_end_at[i + j]++;
        j++;
        continue;
      } else
        break;
    }
    int l = i - 1;
    int r = i;
    while ((l) >= 0 && (r) < n) {
      if (s[l] == s[r]) {
        no_of_p_start_at[l]++;
        no_of_p_end_at[r]++;
        l--;
        r++;
        continue;
      } else
        break;
    }
  }
  psum[0] = 1;
  for (int i = 1; i < n; i++) {
    psum[i] = psum[i - 1] + no_of_p_end_at[i];
  }
  for (int i = 1; i < n; i++) {
    ans += psum[i - 1] * no_of_p_start_at[i];
  }
  cout << ans << endl;
  cin >> ans;
  return 0;
}
