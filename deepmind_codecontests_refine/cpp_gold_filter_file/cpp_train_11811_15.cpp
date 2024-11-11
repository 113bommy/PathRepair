#include <bits/stdc++.h>
using namespace std;
int n, ls;
int a[100005];
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> ls;
    a[ls] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
