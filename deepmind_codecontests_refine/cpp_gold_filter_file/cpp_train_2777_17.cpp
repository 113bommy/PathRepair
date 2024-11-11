#include <bits/stdc++.h>
using namespace std;
const long long N = 4e2 + 5;
const long long mod = 1000000007;
int main() {
  long long n;
  scanf("%lld", &n);
  ;
  vector<long long> num;
  long long count[10] = {0};
  while (n) {
    num.push_back(n % 10);
    count[n % 10]++;
    n = n / 10;
  }
  set<long long> s;
  n = num.size();
  for (long long i = 0; i < (long long)1 << (n); i++) {
    vector<long long> temp;
    for (long long j = 0; j < n; j++) {
      if ((i & ((long long)1 << j))) temp.push_back(num[j]);
    }
    long long hell = 0;
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    long long count1[10] = {0};
    for (auto it : temp) {
      hell = hell * 10 + it;
      count1[it]++;
    }
    bool flag = 1;
    for (long long j = 0; j <= 9; j++) {
      if (count[j] != 0 && count1[j] == 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 0) continue;
    s.insert(hell);
  }
  long long fact[20];
  fact[0] = 1;
  for (long long i = 1; i <= 19; i++) {
    fact[i] = i * fact[i - 1];
  }
  long long ans = 0;
  for (auto it : s) {
    long long count1[10] = {0};
    long long k = it;
    long long sz = 0;
    bool flag = 0;
    while (k) {
      count1[k % 10]++;
      sz++;
      if (k % 10 == 0) flag = 1;
      k = k / 10;
    }
    long long uts = fact[sz];
    for (long long i = 0; i < 10; i++) {
      uts = uts / fact[count1[i]];
    }
    long long uts1 = 0;
    if (flag) {
      uts1 = fact[sz - 1];
      uts1 = uts1 / fact[count1[0] - 1];
      for (long long i = 1; i < 10; i++) {
        uts1 = uts1 / fact[count1[i]];
      }
    }
    uts = uts - uts1;
    ans = ans + uts;
  }
  cout << ans << "\n";
}
