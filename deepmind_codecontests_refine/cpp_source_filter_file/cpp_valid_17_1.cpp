#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void quickSort(int a[], int b[], int l, int r) {
  int p = a[(l + r) / 2];
  int i = l, j = r;
  while (i < j) {
    while (a[i] < p) {
      i++;
    }
    while (a[j] > p) {
      j--;
    }
    if (i <= j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      temp = b[i];
      b[i] = b[j];
      b[j] = temp;
      i++;
      j--;
    }
  }
  if (i < r) {
    quickSort(a, b, i, r);
  }
  if (l < j) {
    quickSort(a, b, l, j);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, a[N][6];
    cin >> n;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= 5; j++) cin >> a[i][j];
    int v = 1;
    for (int i = 2; i <= n; i++) {
      int cnt = 0;
      for (int j = 1; j <= 5; j++)
        if (a[i][j] < a[v][j]) ++cnt;
      if (cnt >= 3) v = i;
    }
    bool ok = 0;
    for (int i = 1; i <= n; i++) {
      if (i == v) continue;
      int cnt = 0;
      for (int j = 1; j <= 5; j++)
        if (a[v][j] > a[i][j]) ++cnt;
      if (cnt >= 3) {
        cout << -1;
        ok = 1;
        break;
      }
    }
    if (!ok) cout << v << endl;
  }
}
