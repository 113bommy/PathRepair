#include <bits/stdc++.h>
using namespace std;
string SubPalindrome(int n, int arr[]) {
  bool ok = false;
  for (int i = 0; i < n; i++) {
    for (int j = i + 2; j < n; j++) {
      if (arr[i] == arr[j]) ok = true;
    }
  }
  if (ok)
    return "YES";
  else
    return "NO";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) cin >> a[i];
    cout << SubPalindrome(N, a);
  }
}
