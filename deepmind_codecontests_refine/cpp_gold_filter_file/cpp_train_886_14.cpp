#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e3 + 5;
int a[N], b[N], c[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      b[j] = 0;
    }
    int maxx = 0;
    for (int j = i; j <= n; j++) {
      int g = a[j];
      b[g]++;
      if (b[g] > b[maxx] || (b[g] == b[maxx] && g < maxx)) {
        maxx = g;
      }
      c[maxx]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << c[i] << " ";
  }
}
