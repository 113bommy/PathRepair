#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int A[1000];
  int ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    int count = 1;
    while (count < k && s[i] == s[i + 1]) {
      count++;
      i++;
    }
    if (count == k) A[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (ans < A[i]) ans = A[i];
  }
  cout << ans << endl;
  return 0;
}
