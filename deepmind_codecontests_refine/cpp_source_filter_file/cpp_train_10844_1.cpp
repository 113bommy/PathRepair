#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0)
    return a;
  else
    return gcd(a % b, b);
}
bool comp(pair<long long int, long long int> x,
          pair<long long int, long long int> y) {
  if (x.first == y.first)
    return y.second < x.second;
  else
    return x < y;
}
int main() {
  long long int i, j;
  long long int t;
  cin >> t;
  while (t--) {
    string m;
    string n;
    cin >> m >> n;
    j = 0;
    bool flag = true;
    for (i = 0; i < n.size(); i++) {
      long long int cnt1 = 1;
      long long int cnt2 = 1;
      while (m[j] == m[j + 1]) {
        j++;
        cnt1++;
      }
      if (m[j] == n[i]) {
        while (n[i] == n[i + 1]) {
          cnt2++;
          i++;
        }
        j++;
        if (cnt2 < cnt1) flag = false;
      } else
        flag = false;
      if (flag == false) break;
    }
    if ((n.size()) < (m.size()) || (j < (m.size() - 1))) flag = false;
    if (flag == false)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
