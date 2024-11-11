#include <bits/stdc++.h>
using namespace std;
void A7med_S3d() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int big(int a, int b) {
  if (a >= b)
    return a;
  else
    return b;
}
bool isprime(int n) {
  if (n == 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
long long nWOZ(long long n) {
  long long sum = 0, c = 1;
  while (n) {
    if (n % 10 != 0) {
      sum += (n % 10) * c;
      c *= 10;
    }
    n /= 10;
  }
  return sum;
}
bool sumofdigit(int n) {
  long long sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  if (sum == 10) return true;
  return false;
}
int main() {
  A7med_S3d();
  int n;
  string s1[100], s2[100];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s1[i] >> s2[i];
  for (int i = 0; i < n; i++)
    if (s2[i] == "rat") cout << s1[i] << endl;
  for (int i = 0; i < n; i++)
    if (s2[i] == "woman" || s2[i] == "child") cout << s1[i] << endl;
  for (int i = 0; i < n; i++)
    if (s2[i] == "man") cout << s1[i] << endl;
  for (int i = 0; i < n; i++)
    if (s2[i] == "captain") cout << s1[i] << endl;
  return 0;
}
