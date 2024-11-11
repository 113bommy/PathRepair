#include <bits/stdc++.h>
using namespace std;
void CI(int &_x) { scanf("%d", &_x); }
void CI(int &_x, int &_y) {
  CI(_x);
  CI(_y);
}
void CI(int &_x, int &_y, int &_z) {
  CI(_x);
  CI(_y, _z);
}
void CI(int &_a, int &_b, int &_c, int &_d) {
  CI(_a, _b);
  CI(_c, _d);
}
template <typename T>
void getarray(T a[], int b, int e) {
  for (int i = b; i < e + b; i++) cin >> a[i];
}
template <typename T>
void printarray(T a[], int b, int e) {
  for (int i = b; i < e - 1 + b; i++) cout << a[i] << " ";
  cout << a[e - 1 + b] << endl;
}
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
template <class T>
inline void read(T &x) {
  bool Minus = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') Minus = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (Minus) x = -x;
};
char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
int dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dr4[4] = {0, 0, 1, -1};
int dc4[4] = {-1, 1, 0, 0};
int kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int main() {
  int i;
  int n, k;
  CI(n, k);
  cout << k * (6 * n - 1) << endl;
  for (i = 0; i < n; i++) {
    int t = 6 * i;
    cout << k * (t + 1) << " ";
    cout << k * (t + 2) << " ";
    cout << k * (t + 3) << " ";
    cout << k * (t + 5) << "\n";
  }
  return 0;
}
