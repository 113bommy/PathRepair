#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
long long gcd(long long m, long long n) { return n ? gcd(n, m % n) : m; }
long long pail(long long m) {
  long long sum = 0;
  long long n = m;
  while (m) {
    sum = sum * 10 + m % 10;
    m /= 10;
  }
  if (n == sum)
    return 1;
  else
    return 0;
}
long long prime(long long n) {
  int f = 0;
  for (long long i = 2; i <= sqrt(n * 1.0); ++i) {
    if (n % i == 0) {
      f = 1;
      return 1;
    }
  }
  if (n == 1 || n == 2) return 0;
  if (f == 0) return 0;
}
void quick_sort(int q[], int l, int r) {
  if (l >= r) return;
  int i = l - 1, j = r + 1, x = q[l + r >> 1];
  while (i < j) {
    do i++;
    while (q[i] < x);
    do j--;
    while (q[j] > x);
    if (i < j) swap(q[i], q[j]);
  }
  quick_sort(q, l, j);
  quick_sort(q, j + 1, r);
}
bool cmp(int a, int b) { return a > b; }
string r = "rock";
string p = "paper";
string s = "scissors";
int main() {
  string a[5];
  int b[3] = {0};
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
    if (a[i] == r)
      b[0]++;
    else if (a[i] == p)
      b[1]++;
    else
      b[2]++;
  }
  if (b[0] == 2 && b[1] == 1 || b[1] == 2 && b[2] == 1 ||
      b[2] == 2 && b[0] == 1) {
    if (a[0] == a[1])
      cout << "S" << endl;
    else if (a[0] == a[2])
      cout << "M" << endl;
    else
      cout << "F" << endl;
  } else
    cout << "?" << endl;
  return 0;
}
