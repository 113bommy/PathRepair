#include <bits/stdc++.h>
using namespace std;
const int maxn = 5;
int n;
int a[20];
long long target;
void ReadData() {
  cin >> n;
  for (int i = 0, _a = ((n) * (n)); i < _a; i++) cin >> a[i];
}
int Code(int x, int y) { return x * n + y; }
long long f(int a[]) {
  long long chinh = 0, phu = 0;
  long long cot[5], hang[5];
  long long res = 0;
  for (int i = 0, _a = n; i < _a; i++) {
    hang[i] = 0;
    for (int j = 0, _a = n; j < _a; j++) hang[i] += a[Code(i, j)];
    res += abs(hang[i] - target);
  }
  for (int j = 0, _a = n; j < _a; j++) {
    cot[j] = 0;
    for (int i = 0, _a = n; i < _a; i++) cot[j] += a[Code(i, j)];
    res += abs(cot[j] - target);
    for (int i = 0, _a = n; i < _a; i++)
      if (i == j) chinh += a[Code(i, j)];
    for (int i = 0, _a = n; i < _a; i++)
      if (i + j == n - 1) phu += a[Code(i, j)];
  }
  res += abs(chinh - target) + abs(phu - target);
  return res;
}
int pos[20];
int b[20];
void Rand(int a[20]) {
  for (int i = 0, _a = ((n) * (n)); i < _a; i++) {
    a[i] = i;
  }
  random_shuffle(a, a + 1 + ((n) * (n)));
}
void Process() {
  for (int i = 0, _a = ((n) * (n)); i < _a; i++) target += a[i];
  target /= n;
  cout << target << "\n";
  for (int step = 0, _a = 2000; step < _a; step++) {
    Rand(pos);
    for (int _a = 0, _b = ((n) * (n)) - 1, i = _a; i <= _b; i++)
      b[i] = a[pos[i]];
    long long last = f(b);
    for (int leo = 0, _a = 3000; leo < _a; leo++) {
      int p1 = rand() % ((n) * (n)), p2 = rand() % ((n) * (n));
      if (p1 == p2) p2 = (p2 + 1) % ((n) * (n));
      swap(b[p1], b[p2]);
      long long cur = f(b);
      if (cur > last) {
        swap(b[p1], b[p2]);
      } else {
        last = cur;
      }
    }
    if (last == 0) {
      for (int i = 0, _a = n; i < _a; i++) {
        for (int j = 0, _a = n; j < _a; j++) cout << b[Code(i, j)] << " ";
        cout << "\n";
      }
      return;
    }
  }
}
int main() {
  std ::ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(time(NULL));
  ReadData();
  Process();
  return 0;
}
