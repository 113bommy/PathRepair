#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, i, a, b, u, v;
  cin >> n >> m;
  v = n;
  u = n;
  long long int arr1[100001] = {0}, arr2[100001] = {0};
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    if (arr1[a] == 0) {
      arr1[a] = 1;
      v--;
    }
    if (arr2[b] == 0) {
      arr2[b] = 1;
      u--;
    }
    cout << (u * v) << " ";
  }
}
