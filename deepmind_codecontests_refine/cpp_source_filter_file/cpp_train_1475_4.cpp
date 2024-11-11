#include <bits/stdc++.h>
using namespace std;
void Fast() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline int RD() {
  int i;
  cin >> i;
  return i;
}
inline float RF() {
  float i;
  cin >> i;
  return i;
}
inline double RDO() {
  double i;
  cin >> i;
  return i;
}
inline string RS() {
  string i;
  cin >> i;
  return i;
}
inline long long RLL() {
  long long i;
  cin >> i;
  return i;
}
int cm[200000];
long long sumSet(int n) { return (1ll * n * (n + 1)) / 2; }
string s;
inline long long fact(int n) {
  long long sum = 1;
  for (int i = 1; i <= n; ++i) {
    sum *= i;
  }
  return sum;
}
long long permtution(string s) {
  long long tot = 1;
  int arr[26] = {};
  for (int i = 0; i < s.size(); ++i) {
    arr[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; ++i) {
    if (arr[i] > 1) tot *= fact(arr[i]);
  }
  int sz = s.size();
  long long per = fact(sz);
  long long ans = per / tot;
  return ans;
}
bool isPrime(int n) {
  if (n == 1) return false;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
int sumDigit(int n) {
  int sum = 0;
  while (n != 0) {
    sum += +n % 10;
    n = n / 10;
  }
  return sum;
}
long long power2(int n) {
  long long ans = (1 << n);
  return ans;
}
long long ans, sum;
int main() {
  Fast();
  int n = RD(), arr[n + 3];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr);
  int day = 1;
  for (int i = 0; i < n; ++i) {
    if (arr[i] >= day) day++;
  }
  cout << day - 1;
}
