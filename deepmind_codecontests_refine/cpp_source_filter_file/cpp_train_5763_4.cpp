#include <bits/stdc++.h>
inline int getInt() {
  int s;
  scanf("%d", &s);
  return s;
}
using namespace std;
int a[1000][1000];
int hss[1000];
int wss[1000];
long long dbl(long long a) { return a * a; }
int main() {
  const int h = getInt();
  const int w = getInt();
  for (int i = 0; i < (int)(h); i++)
    for (int j = 0; j < (int)(w); j++) a[i][j] = getInt();
  for (int i = 0; i < (int)(h); i++)
    for (int j = 0; j < (int)(w); j++) hss[i] += a[i][j];
  for (int i = 0; i < (int)(h); i++)
    for (int j = 0; j < (int)(w); j++) wss[j] += a[i][j];
  long long sum = 0;
  long long mx = 1ll << 60;
  int y = 0;
  for (int i = 0; i < (int)(h + 1); i++) {
    long long tmp = 0;
    for (int j = 0; j < (int)(h); j++) {
      tmp += hss[j] * dbl(std::abs(i * 4 - (j * 4 + 2)));
    }
    if (tmp < mx) {
      mx = tmp;
      y = i;
    }
  }
  sum += mx;
  mx = 1ll << 60;
  int x = 0;
  for (int i = 0; i < (int)(w + 1); i++) {
    long long tmp = 0;
    for (int j = 0; j < (int)(w); j++) {
      tmp += wss[j] * dbl(std::abs(i * 4 - (j * 4 + 2)));
    }
    if (tmp < mx) {
      mx = tmp;
      x = i;
    }
  }
  sum += mx;
  cout << sum << endl;
  cout << x << " " << y << endl;
  return 0;
}
