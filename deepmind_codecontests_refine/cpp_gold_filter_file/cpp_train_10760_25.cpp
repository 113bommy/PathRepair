#include <bits/stdc++.h>
using namespace std;
vector<long long int> isprime;
void seive(long long int size) {
  isprime.resize(size + 1, 1);
  long long int i, j;
  isprime[0] = 0;
  isprime[1] = 0;
  for (i = 2; i * i <= size; i++) {
    if (isprime[i]) {
      for (j = 2; j * i <= size; j++) isprime[i * j] = 0;
    }
  }
}
long long int power(long long int x, unsigned long long int y,
                    long long int m) {
  if (y == 0) return 1;
  long long int p = power(x, y / 2, m);
  p = (p * p) % m;
  if (y % 2 != 0) p = (p * x) % m;
  return p;
}
long long int modinverse(long long int a, long long int m) {
  return power(a, m - 2, m);
}
long long int findans() {
  long long int n, k;
  cin >> n >> k;
  long long int i, j;
  vector<long long int> in((n * k) + 1, 0), v(k);
  for (i = 0; i < k; i++) {
    cin >> v[i];
    in[v[i]] = 1;
  }
  long long int c = 1;
  for (i = 0; i < k; i++) {
    cout << v[i] << " ";
    for (j = 0; j < n - 1; j++) {
      while (in[c] != 0) c++;
      cout << c++ << " ";
    }
    cout << endl;
  }
  return 0;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, i;
  t = 1;
  for (i = 0; i < t; i++) {
    findans();
  }
  return 0;
}
