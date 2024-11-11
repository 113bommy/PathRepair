#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void rd(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void wr(T &...args) {
  ((cout << args << " "), ...);
}
int gcd(int a, int b);
int lcm(int a, int b);
long long _sum(vector<int> a);
template <typename T>
void swap(T &n1, T &n2) {
  T temp;
  temp = n1;
  n1 = n2;
  n2 = temp;
}
void Amritesh() {
  int n, a, b;
  rd(n, a, b);
  bool ok = false;
  int k;
  for (int(i) = (0); (i) < (9); (i)++) {
    k = n * 10 + i;
    if (k % a == 0) {
      ok = true;
      break;
    }
  }
  if (ok == true) {
    cout << k;
    for (int(i) = (0); (i) < (b - 1); (i)++) cout << "0";
  } else {
    cout << "-1";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    Amritesh();
  }
  return 0;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
long long _sum(vector<int> a) { return accumulate(a.begin(), a.end(), 0ll); }
