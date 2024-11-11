#include <bits/stdc++.h>
using namespace std;
int n;
bool check[100000];
int main() {
  cin >> n;
  memset(check, true, sizeof(check));
  for (int i = 1; i < n; i++) {
    int u;
    cin >> u;
    check[u] = false;
  }
  for (int i = 1; i <= n; i++) {
    if (check[i]) cout << i << endl;
  }
}
