#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int sum = 0;
  cin >> n;
  vector<char> v(n);
  for (int i = 0; i < n - 1; i += 2) {
    cin >> v[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == v[i + 1]) {
      sum++;
    }
  }
  cout << sum;
  return 0;
}
