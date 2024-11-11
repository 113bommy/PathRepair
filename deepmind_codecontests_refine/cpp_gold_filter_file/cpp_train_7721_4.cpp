#include <bits/stdc++.h>
using namespace std;
long long power(long long base, long long e) {
  long long answer = 1;
  while (e) {
    if (e % 2 == 1) {
      answer *= base;
    }
    base *= base;
    e /= 2;
  }
  return answer;
}
int main() {
  long long i, n, m, k, j;
  cin >> n >> m;
  string s[n];
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }
  long long a[m];
  for (i = 0; i < m; i++) {
    cin >> a[i];
  }
  long long sum = 0;
  for (i = 0; i < m; i++) {
    long long f[5] = {0};
    for (j = 0; j < n; j++) {
      f[s[j][i] - 'A']++;
    }
    long long max = f[0];
    for (j = 1; j < 5; j++) {
      if (max <= f[j]) max = f[j];
    }
    sum += (max * a[i]);
  }
  cout << sum;
}
