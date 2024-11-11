#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  vector<long long int> v;
  while (n--) {
    long long int x;
    cin >> x;
    v.push_back(x);
  }
  long long int g = v[0];
  for (long long int i = 1; i < v.size(); i++) {
    g = gcd(g, v[i]);
  }
  if (g != v[0]) {
    cout << "-1";
  } else {
    cout << (2 * v.size()) - 1;
    for (long long int i = 1; i < v.size(); i++) {
      if (i == v.size() - 1) {
        cout << v[i];
      } else {
        cout << v[i] << " " << v[0] << " ";
      }
    }
  }
  return 0;
}
