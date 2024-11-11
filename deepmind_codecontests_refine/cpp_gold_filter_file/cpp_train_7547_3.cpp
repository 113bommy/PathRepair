#include <bits/stdc++.h>
using namespace std;
long long a[100500];
long long n, q;
long long sparse[100500][20];
void proc(long long* a, int n) {
  for (int i = 0; i < n; i++) {
    sparse[i][0] = i;
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      if (a[sparse[i][j - 1]] > a[sparse[i + (1 << (j - 1))][j - 1]]) {
        sparse[i][j] = sparse[i][j - 1];
      } else {
        sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}
long long max(int l, int r) {
  int k = r - l + 1;
  int ll = log(k) / log(2);
  if (a[sparse[l][ll]] > a[sparse[l + k - (1 << ll)][ll]]) {
    return sparse[l][ll];
  } else {
    return sparse[l + k - (1 << ll)][ll];
  }
}
long long rez(int l, int r) {
  if (l == r) return a[l];
  if (l > r) return 0;
  long long rezult = 0;
  long long pos = max(l, r);
  rezult = 1LL * a[pos] * (r - pos + 1) * (pos - l + 1);
  rezult += rez(l, pos - 1) + rez(pos + 1, r);
  return rezult;
}
int main() {
  long long k = 0;
  long long prev = 0;
  cin >> n;
  cin >> q;
  a[0] = 0;
  cin >> prev;
  for (int i = 1; i < n; i++) {
    cin >> k;
    a[i] = abs(prev - k);
    prev = k;
  }
  proc(a, n);
  int x = 0, y = 0;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    cout << rez(x, y - 1) << endl;
  }
  return 0;
}
