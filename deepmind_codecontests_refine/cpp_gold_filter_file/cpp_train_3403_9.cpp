#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> s;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int z;
    cin >> z;
    s.insert(z);
    v.push_back(z);
  }
  int maxi = 1;
  int a, b;
  for (long long int i = 1; i <= 2000000001; i *= 2) {
    for (int j = 0; j < n; j++) {
      if (s.find(v[j] + i) == s.end()) {
        continue;
      } else {
        maxi = 2;
        a = v[j];
        b = v[j] + i;
        if (s.find(b + i) != s.end()) {
          cout << 3 << endl;
          cout << a << " " << a + i << " " << a + i + i << endl;
          return 0;
        }
      }
    }
  }
  if (maxi == 1) {
    cout << 1 << endl;
    cout << v[0];
    return 0;
  }
  if (maxi == 2) {
    cout << 2 << endl;
    cout << a << " " << b;
  }
}
