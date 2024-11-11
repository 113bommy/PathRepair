#include <bits/stdc++.h>
using namespace std;
long long dp[20][20][2];
void getDigits(int n, vector<int> &v) {
  if (n == 0) {
    v.push_back(0);
    return;
  }
  while (n > 0) {
    v.push_back(n % 10);
    n /= 10;
  }
}
long long res(int index, int broji, int pojavljivanje, vector<int> &v) {
  if (broji > 3) {
    return 0;
  }
  if (index == (int)v.size()) {
    if (broji <= 3) {
      return 1;
    } else {
      return 0;
    }
  }
  if (dp[index][broji][pojavljivanje] != -1) {
    return dp[index][broji][pojavljivanje];
  }
  long long rezultat = 0;
  int granica = 100;
  if (pojavljivanje == 0) {
    granica = v[index];
  } else {
    granica = 9;
  }
  for (int i = 0; i <= granica; i++) {
    int novoPojavljivanje = pojavljivanje;
    int noviBrojac = broji;
    if (pojavljivanje == 0 && i < v[index]) {
      novoPojavljivanje = 1;
    }
    if (i != 0) {
      noviBrojac++;
    }
    if (novoPojavljivanje <= 3) {
      rezultat += res(index + 1, noviBrojac, novoPojavljivanje, v);
    }
  }
  dp[index][broji][pojavljivanje] = rezultat;
  return rezultat;
}
long long solve(long long n) {
  memset(dp, -1, sizeof(dp));
  vector<int> v;
  getDigits(n, v);
  reverse((v).begin(), (v).end());
  return res(0, 0, 0, v);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << '\n';
  }
  return 0;
}
