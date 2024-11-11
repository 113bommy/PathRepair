#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 4e6;
const long long mod = 1e6 + 3;
long long log_10(long long n) {
  long long cnt = 0;
  while (n >= 10) {
    n /= 10;
    cnt++;
  }
  return cnt;
}
void NO_Exit() {
  cout << "NO" << endl;
  exit(0);
}
void NO() { cout << "NO" << endl; }
void YES_Exit() {
  cout << "YES" << endl;
  exit(0);
}
void YES() { cout << "YES" << endl; }
void coiarr(long long a[], long long n) {
  if (n == 0) return;
  cout << a[0];
  for (long long i = 1; i < n; i++) cout << " " << a[i];
}
void cosarr(string a[], long long n) {
  if (n == 0) return;
  cout << a[0];
  for (long long i = 1; i < n; i++) cout << " " << a[i];
}
void ciiarr(long long a[], long long n) {
  for (long long i = 0; i < n; i++) cin >> a[i];
}
void cisarr(string a[], long long n) {
  for (long long i = 0; i < n; i++) cin >> a[i];
}
void fill_bool(bool a[], long long n, bool flag) {
  for (long long i = 0; i < n; i++) a[i] = flag;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout << "INTERCAL";
  return 0;
}
