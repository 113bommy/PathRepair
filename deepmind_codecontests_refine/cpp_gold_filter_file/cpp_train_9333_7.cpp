#include <bits/stdc++.h>
using namespace std;
int main() {
  long long X, d;
  cin >> X >> d;
  vector<long long> v;
  long long r = 1;
  for (int i = 0; i <= 60; i++) {
    if (((X >> i) & 1)) {
      r += d;
      for (int j = 0; j < i; j++) {
        v.push_back(r);
      }
      r = r + d;
      v.push_back(r);
    }
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
