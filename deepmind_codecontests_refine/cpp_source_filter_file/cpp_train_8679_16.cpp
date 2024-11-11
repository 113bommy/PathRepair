#include <bits/stdc++.h>
using namespace std;
int a[3005], n, i = 1, t;
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> t;
    a[t]++;
  }
  for (int i = 1; i <= 3005; i++)
    if (a[i] == 0) {
      cout << i;
      break;
    }
}
