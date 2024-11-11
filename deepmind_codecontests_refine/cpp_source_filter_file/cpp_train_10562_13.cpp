#include <bits/stdc++.h>
using namespace std;
long long power_wm(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long power(long long x, long long y, long long p = 1000000007) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void print_vector(vector<long long> a) {
  for (long long i = 0; i < a.size(); i++) cout << a[i] << " ";
  cout << '\n';
}
void initialize(vector<long long> &arr, long long n) {
  for (long long i = 0; i <= n; i++) arr[i] = i;
}
long long root(vector<long long> &arr, long long i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}
void Union(vector<long long> &arr, long long a, long long b) {
  long long root_a = root(arr, a);
  long long root_b = root(arr, b);
  arr[root_a] = root_b;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
struct node {
  long long val = 99999999999999999;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  string hr, vr;
  cin >> hr;
  cin >> vr;
  if (hr[0] == hr[n - 1]) {
    cout << "NO";
    return 0;
  }
  if (vr[0] == vr[m - 1]) {
    cout << "NO";
    return 0;
  }
  if (hr[0] == '>' and vr[0] == 'V') {
    cout << "NO";
    return 0;
  }
  if (hr[0] == '<' and vr[0] == '^') {
    cout << "NO";
    return 0;
  }
  cout << "YES";
}
