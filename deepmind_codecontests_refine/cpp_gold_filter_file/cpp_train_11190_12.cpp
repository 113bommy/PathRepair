#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long n, long long temp) {
  long long res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
vector<long long> arr, cit, sign;
map<long long, int> mapit;
int main() {
  long long w, m, c1, c2, c3, c4, calc, flag = 0, sz, j, i, k, i1, j1, cnt;
  scanf("%lld", &w);
  scanf("%lld", &m);
  if (w == 2) {
    cout << "YES" << endl;
  } else {
    calc = 1;
    while (calc <= (int)(1e9 + 7)) {
      arr.push_back(calc);
      calc *= w;
    }
    arr.push_back(calc);
    sz = arr.size();
    calc = 1 << sz;
    cit.push_back(0);
    mapit[0] = 1;
    for (i = 1; i < calc; ++i) {
      i1 = i;
      c1 = 0;
      cnt = 0;
      while (i1 != 0) {
        if (i1 % 2 == 1) c1 += arr[cnt];
        cnt++;
        i1 /= 2;
      }
      mapit[c1]++;
      cit.push_back(c1);
    }
    sz = cit.size();
    for (i = 0; i < sz; ++i) {
      mapit[cit[i]]--;
      calc = m + cit[i];
      if (mapit.find(calc) != mapit.end()) {
        if (mapit[calc] == 1) {
          flag = 1;
          break;
        }
      }
      mapit[cit[i]]++;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
