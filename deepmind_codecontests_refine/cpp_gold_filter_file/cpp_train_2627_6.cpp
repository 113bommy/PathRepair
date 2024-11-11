#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, i, n;
  vector<long long int> v, v1;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  b = v[0];
  v1.push_back(b);
  for (i = 1; i < n; i++) {
    a = v[i] + b;
    v1.push_back(a);
    if (a > b) {
      b = a;
    }
  }
  for (i = 0; i < v1.size(); i++) {
    cout << v1[i] << " ";
  }
  return 0;
}
