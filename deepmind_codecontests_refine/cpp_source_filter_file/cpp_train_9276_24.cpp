#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int a[101] = {0};
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      a[x]++;
    }
  }
  for (int i = 0; i < 101; i++) {
    if (a[i] == n) cout << i;
  }
}
