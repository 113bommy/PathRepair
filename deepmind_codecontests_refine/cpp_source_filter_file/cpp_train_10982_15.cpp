#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
  for (int i = 2; i < n; i++) {
    if (a[i] == 1) continue;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] % i == 0) {
        a[j] /= i;
      }
    }
  }
  vector<int> v;
  for (int i = 2; i <= n; i++) {
    if (a[i] != 1) {
      v.push_back(i);
    }
  }
  cout << v.size() << "\n";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
