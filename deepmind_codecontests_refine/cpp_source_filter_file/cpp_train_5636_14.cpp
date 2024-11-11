#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:20000000")
string problem_name = "a";
void init() { freopen((problem_name + ".in").c_str(), "rt", stdin); }
int mas[111];
int val[1000100];
int calc(int t) {
  int sum = 0;
  while (t) {
    sum += t % 10;
    t /= 10;
  }
  sum %= 9;
  if (sum == 0) sum = 9;
  return sum;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    int t = i;
    while (t) {
      sum += t % 10;
      t /= 10;
    }
    sum %= 9;
    if (sum == 0) sum = 9;
    val[i] = sum;
    mas[sum]++;
  }
  long long res = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; i * j <= n; j++) {
      if (val[i] * val[j] == val[i * j]) res++;
    }
  long long col = 0;
  for (int i = 1; i <= 9; i++)
    for (int j = 1; j <= 9; j++) {
      int v = calc(i * j);
      col += mas[i] * (long long)mas[j] * (long long)mas[v];
    }
  cout << col - res;
  return 0;
}
