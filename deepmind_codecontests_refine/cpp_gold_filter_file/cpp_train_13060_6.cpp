#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v;
int main() {
  cin >> n;
  for (int i = 4; i <= n; i++) {
    if (i % 2 == 0 || i % 3 == 0) {
      v.push_back(i);
    }
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      if (v[i] + v[j] == n) {
        cout << v[i] << " " << v[j] << endl;
        return 0;
      }
    }
  }
  return 0;
}
