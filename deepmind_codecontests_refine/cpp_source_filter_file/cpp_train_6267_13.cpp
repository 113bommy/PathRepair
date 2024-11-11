#include <bits/stdc++.h>
using namespace std;
vector<long long> printDivisors(long long n) {
  vector<long long> v;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (n / i != i) v.push_back(n / i);
    }
  }
  return v;
}
int main() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long cnt = 0, flag = 0;
  vector<long long> pos;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    cnt += v[i];
    if (v[i] == 1) {
      pos.push_back(i + 1);
    }
  }
  long long val = 0, ans = INT_MAX;
  vector<long long> v1 = printDivisors(cnt);
  if (cnt == 1) {
    cout << "-1";
  } else {
    for (int k = 0; k < (long long)v1.size(); k++) {
      if (v1[k] == 1) {
        continue;
      }
      val = v1[k];
      long long mid = val / 2;
      long long temp = 0;
      for (int i = 0; i < (long long)pos.size(); i += val) {
        mid = i + val / 2;
        for (int j = i; j < i + val; j++) {
          temp += abs(pos[j] - pos[mid]);
        }
      }
      ans = min(ans, temp);
    }
    cout << ans;
  }
}
