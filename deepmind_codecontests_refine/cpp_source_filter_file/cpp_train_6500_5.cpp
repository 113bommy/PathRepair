#include <bits/stdc++.h>
using namespace std;
const int n = 1e6 + 1;
int freq[26];
int freq1[26], freq2[26];
int fac = 1;
bool f[n];
const int N = 1e6 + 1;
int cum[N], cum1[N];
vector<int> primes;
void sevive() {
  memset(f, true, sizeof f);
  f[0] = false;
  f[1] = false;
  for (int i = 2; i * i < n; i++) {
    if (f[i]) {
      for (int j = i + i; j < n; j += i) f[j] = false;
    }
  }
  for (int i = 0; i < n; i++)
    if (f[i]) primes.push_back(i);
}
int GCD(int x, int y) {
  int t;
  while (y) {
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}
void copy(int a[], int a2[], int l, int h) {
  if (l > h)
    return;
  else {
    a2[l] = a[l];
    copy(a, a2, l + 1, h);
  }
}
long long fac1(int n) {
  if (n == 1)
    return 1;
  else {
    return n * fac1(n - 1);
  }
}
int main() {
  int n, a;
  cin >> n;
  cum[0] = 0;
  cum1[0] = 0;
  vector<int> v1;
  vector<int> v2;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    v1.push_back(a);
    v2.push_back(a);
  }
  sort(v2.begin(), v2.end());
  for (int i = 1; i <= v1.size(); ++i) {
    cum[i] = cum[i - 1] + v1[i - 1];
  }
  for (int i = 1; i <= v2.size(); ++i) {
    cum1[i] = cum1[i - 1] + v2[i - 1];
  }
  int n1, a1, b1, c1;
  cin >> n1;
  while (n1--) {
    cin >> a1 >> b1 >> c1;
    if (a1 == 1) {
      cout << cum[c1] - cum[b1 - 1] << endl;
    } else
      cout << cum1[c1] - cum1[b1 - 1] << endl;
  }
  return 0;
}
