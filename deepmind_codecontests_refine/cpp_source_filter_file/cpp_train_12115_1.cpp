#include <bits/stdc++.h>
using namespace std;
int bmm(int k) {
  int amel[16] = {0};
  for (int i = 2; i <= k; i++) {
    int n = i, a = 2;
    int a1[16] = {0};
    while (n != 1) {
      while (n % a == 0) {
        n /= a;
        a1[a]++;
      }
      a++;
    }
    for (int j = 0; j < 16; j++)
      if (a1[j] > amel[j]) amel[j] = a1[j];
  }
  int res = 1;
  for (int i = 2; i <= 15; i++)
    for (int k = 0; k < amel[i]; k++) res *= i;
  return res;
}
int k;
long long time(long long a, long long b) {
  int t = 0;
  while (a > b) {
    int max = 0;
    for (int i = 2; i <= k; i++)
      if (a % i > max && a - b >= a % i) max = a % i;
    if (max == 0) max = 1;
    a -= max;
    t++;
  }
  return t;
}
int main() {
  ifstream inf("in.txt");
  long long a, b;
  cin >> a >> b >> k;
  int step = bmm(k);
  if ((long long)(a / step) == (long long)(b / step)) {
    cout << time(a, b) << endl;
  } else {
    long long t = time(a % step, 0);
    t += ((long long)(a / step) - (long long)(b / step) - 1) * time(step, 0);
    t += time(step, b);
    cout << t << endl;
  }
}
