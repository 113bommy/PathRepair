#include <bits/stdc++.h>
using namespace std;
long long sum[100009], v[100009], cate[100009], cat[100009], val[100009], n, m,
    task, x, y, nr;
long long cb(long long poz) {
  long long st = 1, dr = m, mid, sol;
  while (st <= dr) {
    mid = st + (dr - st) / 2;
    if (sum[mid - 1] <= poz && sum[mid] >= poz) {
      sol = mid;
      st = dr + 1;
    } else {
      if (sum[mid] < poz)
        st = mid + 1;
      else
        dr = mid - 1;
    }
  }
  if (val[sol] != 0) return val[sol];
  poz -= sum[sol - 1];
  if (poz % cate[sol] == 0) return v[cate[sol]];
  poz %= cate[sol];
  return v[poz];
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> task;
    if (task == 1) {
      cin >> val[i];
      if (nr < 100000) v[++nr] = val[i];
      sum[i] = sum[i - 1] + 1;
    } else {
      cin >> cate[i] >> cat[i];
      for (int q = 1; q <= cat[i]; ++q)
        for (int j = 1; j <= cate[i]; ++j)
          if (nr < 100000)
            v[++nr] = v[j];
          else {
            j = cate[i];
            q = cat[i] + 1;
          }
      sum[i] = sum[i - 1] + 1LL * cate[i] * cat[i];
    }
  }
  cin >> n;
  while (n--) {
    long long poz;
    cin >> poz;
    cout << cb(poz) << ' ';
  }
  return 0;
}
