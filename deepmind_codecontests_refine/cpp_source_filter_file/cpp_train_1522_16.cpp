#include <bits/stdc++.h>
using namespace std;
const int M = 50010, mod = 1000000007, OPT = 150;
int f[M];
bitset<(1000000000 / OPT) + 10> g;
vector<int> p;
bool isprime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
int NN, DD, ANS;
void track(int i, int taken, int sum) {
  if (p[i] >= DD) {
    if (taken % 2 == 0)
      ANS += NN / (sum * DD);
    else
      ANS -= NN / (sum * DD);
  } else {
    if (sum * p[i] <= NN / DD) track(i + 1, taken + 1, sum * p[i]);
    track(i + 1, taken, sum);
  }
}
int solve_for(int n, int d) {
  int i, j, k;
  if (n < d) return 0;
  if (d < OPT) {
    NN = n;
    DD = d;
    ANS = 0;
    track(0, 0, 1);
    return ANS;
  } else {
    int r = n / d;
    for (i = 0; i <= r; i++) g[i] = 0;
    for (i = 0; p[i] < d; i++) {
      for (j = 0; j <= r; j += p[i]) g[j] = 1;
    }
    int sum = 0;
    for (i = 1; i <= r; i++) sum += (g[i] == 0);
    return sum;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  int i, j, k;
  int a, b, sum = 0;
  for (i = 2; i < M; i++) {
    if (!f[i]) {
      p.push_back(i);
      for (j = i; j < M; j += i) f[j] = 1;
    }
  }
  scanf("%d%d%d", &a, &b, &k);
  if (isprime(k) == 0)
    printf("%d\n", 0);
  else {
    if ((long long)k * (long long)k > (long long)b)
      printf("%d\n", k >= a && k <= b);
    else {
      printf("%d\n", solve_for(b, k) - solve_for(a, k));
    }
  }
  return 0;
}
