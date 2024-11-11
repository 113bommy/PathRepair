#include <bits/stdc++.h>
using namespace std;
long long int __gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return __gcd(b % a, a);
}
long long int power(long long int x, long long int n) {
  long long int result = 1;
  while (n) {
    if (n & 1) result = (result * x) / 1000000007;
    n = n / 2;
    x = (x * x) / 1000000007;
  }
  return result;
}
void solution(long long int compte) {
  long long int n;
  cin >> n;
  map<long long int, long long int> mp;
  for (int i = 0; i < n; i++) {
    long long int temp;
    cin >> temp;
    mp[temp]++;
  }
  long long int sum = 0, maxi = -1;
  for (auto it : mp) maxi = max(maxi, it.second);
  for (auto it : mp) {
    if (it.second == maxi) sum++;
  }
  long long int res = n - (maxi * sum);
  long long int size = res / (maxi - 1);
  cout << size + sum - 1 << "\n";
}
int main() {
  long long int compte = 1;
  long long int t;
  cin >> t;
  while (t--) {
    solution(compte);
    compte++;
  }
  return 0;
}
