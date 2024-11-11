#include <bits/stdc++.h>
using namespace std;
bool prime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
bool power_of_2(long long n) {
  while (n % 2 == 0) n /= 2;
  if (n == 1)
    return true;
  else
    return false;
}
int main() {
  int ttt;
  cin >> ttt;
  for (int uu = 0; uu < ttt; ++uu) {
    long long m, n, k = 0, temp;
    cin >> n;
    vector<long long> vect;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      vect.push_back(temp);
    }
    for (int i = 1; i < n - 1; ++i) {
      if (vect[i] > vect[i - 1] && vect[i + 1] < vect[i]) {
        cout << "YES" << endl;
        cout << i - 1 << " " << i << " " << i + 1 << endl;
        k = 1;
        break;
      }
    }
    if (k == 0) {
      cout << "NO" << endl;
    }
  }
}
