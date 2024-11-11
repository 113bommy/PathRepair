#include <bits/stdc++.h>
using namespace std;
struct LiChao {
  long long l;
  long long r;
  long long rez;
};
LiChao mas[800005];
long long i, j, n, m, ab[200005], rez, sum[200005], atb, x[200005][2], a, b;
void build(long long y, long long l, long long r) {
  if (l != r) {
    build(2 * y + 1, l, l + (r - l) / 2);
    build(2 * y + 2, l + (r - l) / 2 + 1, r);
  }
  mas[y].l = l;
  mas[y].r = r;
  mas[y].rez = -1;
}
void ins(long long y, long long j) {
  long long c = mas[y].l + (mas[y].r - mas[y].l) / 2;
  if (mas[y].rez == -1) {
    mas[y].rez = j;
    return;
  }
  if (mas[y].l == mas[y].r) {
    if (x[j][0] * mas[y].l + x[j][1] <
        x[mas[y].rez][0] * mas[y].l + x[mas[y].rez][1]) {
      mas[y].rez = j;
    }
    return;
  } else {
    long long fl1 = x[mas[y].rez][0] * mas[y].l + x[mas[y].rez][1];
    long long fl2 = x[j][0] * mas[y].l + x[j][1];
    long long fc1 = x[mas[y].rez][0] * c + x[mas[y].rez][1];
    long long fc2 = x[j][0] * c + x[j][1];
    long long fr1 = x[mas[y].rez][0] * mas[y].r + x[mas[y].rez][1];
    long long fr2 = x[j][0] * mas[y].r + x[j][1];
    if (fl1 >= fl2 && fc1 >= fc2 && fr1 >= fr2) {
      mas[y].rez = j;
      return;
    }
    if ((fl1 >= fl2 && fc1 <= fc2) || (fl1 <= fl2 && fc1 >= fc2) ||
        (fc1 <= fc2 && fr1 >= fr2) || (fc1 >= fc2 && fr1 <= fr2)) {
      ins(2 * y + 1, j);
      ins(2 * y + 2, j);
      return;
    }
  }
}
long long f(long long y, long long l) {
  if (mas[y].l == mas[y].r) {
    if (mas[y].rez == -1) {
      return 1000000000000000000;
    }
    return x[mas[y].rez][0] * l + x[mas[y].rez][1];
  }
  if (mas[2 * y + 1].r >= l) {
    if (mas[y].rez == -1) {
      return f(2 * y + 1, l);
    }
    return min(f(2 * y + 1, l), x[mas[y].rez][0] * l + x[mas[y].rez][1]);
  }
  if (mas[y].rez == -1) {
    return f(2 * y + 2, l);
  }
  return min(f(2 * y + 2, l), x[mas[y].rez][0] * l + x[mas[y].rez][1]);
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  i = 1;
  while (i <= n) {
    cin >> ab[i];
    rez += i * ab[i];
    i++;
  }
  i = 1;
  while (i <= n) {
    sum[i] = sum[i - 1] + ab[i];
    i++;
  }
  build(0, 1, n);
  i = 1;
  while (i <= n) {
    if (i != 1) {
      atb = max(atb, -sum[i] - f(0, i));
    }
    x[i][0] = -ab[i];
    x[i][1] = -sum[i] + i * ab[i];
    ins(0, i);
    i++;
  }
  build(0, 1, n);
  i = n;
  while (i >= 1) {
    if (i != n) {
      atb = max(atb, -sum[i - 1] - f(0, i));
    }
    x[i][0] = -ab[i];
    x[i][1] = -sum[i - 1] + i * ab[i];
    ins(0, i);
    i--;
  }
  cout << atb + rez;
  return 0;
}
