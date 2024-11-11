#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int N[1003];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> N[i];
  }
  for (int i = n; i > 0; i--) {
    N[i] -= N[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      for (int z = 1; z <= n; z += i) {
        if (N[z] != N[1]) {
          goto nxt;
        }
      }
    }
    v.push_back(i);
  nxt:;
  }
  n = v.size();
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    cout << v[i] << " \n"[i == n - 1];
  }
  return 0;
}
