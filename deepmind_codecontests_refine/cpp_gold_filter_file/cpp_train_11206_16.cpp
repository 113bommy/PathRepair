#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  while (cin >> n >> k) {
    if (k == 1) {
      cout << "Yes" << endl;
      continue;
    }
    if (n % 2 == 0 && k > 1) {
      cout << "No" << endl;
      continue;
    }
    if ((k - n) > 1) {
      cout << "No" << endl;
      continue;
    }
    map<long long, int> mp;
    bool flag = true;
    if (k > 1000000) {
      k = 1000000;
    }
    for (int i = 1; i <= k; i += 1) {
      mp[n % i]++;
      if (mp[n % i] > 1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
