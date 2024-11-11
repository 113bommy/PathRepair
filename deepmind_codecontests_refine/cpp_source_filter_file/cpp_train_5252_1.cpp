#include <bits/stdc++.h>
using namespace std;
vector<long long int> vc;
map<long long, bool> mp;
long long digitss(long long n) {
  long long res = 0;
  while (n >= 1) {
    res += n % 10;
    n = n / 10;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    vc.push_back(digitss(x));
    mp[digitss(x)] = true;
  }
  sort(vc.begin(), vc.end());
  long long int counter = 0;
  for (int i = 0; i < vc.size(); i++) {
    for (int j = i + 1; j < vc.size(); j++) {
      if ((vc[i] + vc[j]) % 3 == 0 && mp[j] == true && mp[i] == true) {
        counter++;
        mp[j] = false;
        mp[i] = false;
        break;
      }
    }
  }
  cout << counter;
  return 0;
}
