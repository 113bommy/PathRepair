#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int power(long long int n, long long int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  long long int res = power(n, k / 2);
  if (k % 2 == 0) return res * res;
  return res * res * n;
}
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int curr = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a = (s[i] - '0') % 3;
    if (a % 3 == 0) {
      curr = 0;
      sum++;
      continue;
    }
    if ((a + curr) % 3 == 0) {
      curr = 0;
      sum++;
      continue;
    }
    if (curr == 1 && a % 3 == 1) {
      if (i == n - 1) continue;
      curr = 0;
      sum++;
      i++;
      continue;
    }
    if (curr == 2 && a % 3 == 2) {
      if (i == n - 1) continue;
      curr = 0;
      sum++;
      i++;
      continue;
    }
    if (curr == 0 && a % 3 == 1) {
      if (i == n - 1 || (s[i + 1] - '0') % 3 == 1) {
        curr = 1;
        continue;
      }
      curr = 0;
      sum++;
      i++;
      continue;
    }
    if (curr == 0 && a % 3 == 2) {
      if (i == n - 1 || (s[i + 1] - '0') % 3 == 2) {
        curr = 2;
        continue;
      }
      curr = 0;
      sum++;
      i++;
      continue;
    }
  }
  cout << sum << endl;
  return 0;
}
