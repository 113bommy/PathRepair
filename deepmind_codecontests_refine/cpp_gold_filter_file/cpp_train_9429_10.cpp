#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 2; j < n; j++) {
      if ((ar[i] + ar[i + 1]) > ar[j]) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
