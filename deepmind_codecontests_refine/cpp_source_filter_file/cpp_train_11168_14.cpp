#include <bits/stdc++.h>
using namespace std;
inline long long int add(long long int a, long long int b) {
  return ((a % 1000000007LL) + (b % 1000000007LL)) % 1000000007LL;
}
inline long long int mul(long long int a, long long int b) {
  return ((a % 1000000007LL) * (b % 1000000007LL)) % 1000000007LL;
}
inline long long int sub(long long int a, long long int b) {
  return ((a % 1000000007LL) - (b % 1000000007LL) + 1000000007LL) %
         1000000007LL;
}
void Ojas() {
  long long int n;
  cin >> n;
  long long int temp = n;
  long long int sum[n];
  long long int ans;
  cout << "1 " << n << "\n";
  cin >> ans;
  sum[n - 1] = ans;
  long long int ar[n];
  while (n > 2) {
    cout << "1 " << n - 1 << "\n";
    cin >> ans;
    n--;
    sum[n - 1] = ans;
  }
  cout << "2 " << temp << "\n";
  cin >> ans;
  for (long long int i = temp - 1; i > 0; i--) {
    ar[i] = sum[i] - sum[i - 1];
  }
  ar[0] = sum[temp - 1] - ans;
  ar[1] = sum[1] - ar[0];
  cout << "! ";
  for (int i = 0; i < temp; i++) {
    cout << ar[i] << " ";
  }
}
int main() {
  long long int t = 1;
  for (long long int i = 1; i <= t; i++) {
    Ojas();
  }
  return 0;
}
