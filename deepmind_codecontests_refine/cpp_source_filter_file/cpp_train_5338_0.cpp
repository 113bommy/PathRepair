#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
inline T bigmod(T p, T e, T M) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    long long int t = bigmod(p, e / 2, M);
    return (T)((t * t) % M);
  }
  return (T)((long long int)bigmod(p, e - 1, M) * (long long int)p) % M;
}
inline long long int mod(long long int a, long long int m) {
  return (a % m + m) % m;
}
void Porcupine_Tree() {
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (n <= 2) {
      if (i == 0) cout << "0" << endl;
      cout << a[i] << " ";
    }
  }
  if (n <= 2) {
    cout << endl;
    return;
  }
  sort(a, a + n);
  cout << n / 2 << endl;
  int high = n - 1;
  int low = 0;
  i = 0;
  while (low <= high) {
    if (i & 1) {
      cout << a[low] << " ";
      low++;
    } else {
      cout << a[high] << " ";
      high--;
    }
    i++;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  while (tc--) {
    Porcupine_Tree();
  }
  exit(0);
}
