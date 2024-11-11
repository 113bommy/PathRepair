#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) - 1;
const long double eps = 1e-9;
const long double pi = fabs(atan2(0.0, -1.0));
int *ass;
void ML() {
  for (;;) {
    ass = new int[2500000];
    for (int i = 0; i < 2500000; i++) ass[i] = rand();
  }
}
int n, wins_min, k;
vector<int> a, p;
void LoAd() {
  cin >> n >> wins_min >> k;
  a.resize(n);
  p.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) a[i] += 1;
}
double sv[205][205][205];
double rec(const int left, const int wins, int wegh) {
  if (left == n) {
    if (wins >= wins_min && wegh >= wins)
      return 1.0;
    else
      return 0.0;
  }
  if (wegh > 200) wegh = 200;
  if (sv[left][wins][wegh] > -2) return sv[left][wins][wegh];
  double res = 0.0;
  double n1 = rec(left + 1, wins + 1, wegh + a[left]);
  n1 *= 0.01 * p[left];
  res += n1;
  double n2 = rec(left + 1, wins, wegh);
  n2 *= 0.01 * (100 - p[left]);
  res += n2;
  sv[left][wins][wegh] = res;
  return res;
}
void SoLvE() {
  for (int i = 0; i < 205; i++)
    for (int j = 0; j < 205; j++)
      for (int k = 0; k < 205; k++) sv[i][j][k] = -5;
  double res = rec(0, 0, k);
  res += 0.000001;
  printf("%0.8f", res);
}
int main() {
  srand((int)time(NULL));
  LoAd();
  SoLvE();
  return 0;
}
