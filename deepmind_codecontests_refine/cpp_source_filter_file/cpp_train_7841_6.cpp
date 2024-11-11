#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979;
const double PI2 = 6.28318530717958;
const double PId2 = 1.570796326794895;
inline vector<int> ReadVI(int count) {
  vector<int> arrayname(count);
  for (int i = 0; i < int(count); i++) cin >> arrayname[i];
  return arrayname;
};
inline vector<pair<int, int> > ReadVII(int count) {
  vector<pair<int, int> > arrayname(count);
  for (int i = 0; i < int(count); i++) {
    cin >> arrayname[i].first;
    arrayname[i].second = i;
  }
  return arrayname;
};
const int MOD = 1000000007;
const int MAXVALUE = 100001;
vector<int> sieve(int n) {
  int *r = new int[n]();
  r[0] = r[1] = 1;
  for (int i = 1; i < sqrt(n); i++) {
    if (r[i] == 0) {
      for (int j = i; j < n; j += i) r[j] = 1;
      r[i] = 0;
    }
  }
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (r[i] == 0) res.push_back(i);
  }
  delete[] r;
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<int> pr = sieve(1000);
  long long res = 0;
  while (n > 1) {
    res += n;
    int i = 0;
    bool flag = false;
    for (; i < pr.size() && pr[i] * pr[i] <= n; i++) {
      if (n % pr[i] == 0) {
        flag = true;
        break;
      }
    }
    if (flag)
      n /= pr[i];
    else
      n = 1;
  }
  cout << res + 1;
  return 0;
}
