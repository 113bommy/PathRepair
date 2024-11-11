#include <bits/stdc++.h>
using namespace std;
void main2() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  if (v[0] == 1) {
    cout << n + 1 << " ";
    for (long long int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";
  } else if (v[n - 1] == 0) {
    for (long long int i = 1; i <= n; i++) cout << i << " ";
    cout << n + 1 << "\n";
  } else {
    for (long long int i = 1; i < n; i++) {
      if (v[i - 1] == 0 && v[i] == 1) {
        for (long long int j = 0; j <= i - 1; j++) cout << j + 1 << " ";
        cout << n + 1 << " ";
        for (long long int j = i; j < n; j++) cout << j + 1 << " ";
        cout << "\n";
        return;
      }
    }
    cout << "-1\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    main2();
  }
  return 0;
}
