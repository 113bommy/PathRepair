#include <bits/stdc++.h>
using namespace std;
bool isPrime[400];
vector<int> prime;
vector<int> factor[12005];
int primeCnt[80];
void make_prime() {
  for (int i = 0; i < 400; i++) isPrime[i] = true;
  for (int i = 2; i < 400; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j < 400; j += i) isPrime[j] = false;
      prime.push_back(i);
    }
  }
}
void dfs(int i, int num, int index, int res) {
  if (i == 79) {
    if (res != 1) factor[index].push_back(num * res);
    factor[index].push_back(num);
    return;
  }
  for (int j = 0; j <= primeCnt[i]; j++) {
    dfs(i + 1, num, index, res);
    num *= prime[i];
  }
}
void make_factor() {
  factor[1].push_back(1);
  for (int i = 2; i <= 12000; i++) {
    memset(primeCnt, 0, sizeof(primeCnt));
    int tmp = i;
    for (int j = 0; j < prime.size(); j++)
      while (tmp % prime[j] == 0) {
        primeCnt[j]++;
        tmp /= prime[j];
      }
    dfs(0, 1, i, tmp);
    sort(factor[i].begin(), factor[i].end());
  }
}
int main() {
  make_prime();
  make_factor();
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 1000000000;
    int ansA, ansB, ansC;
    for (int i = b; i >= 1; i--) {
      if (b - i > ans) break;
      int tmp = b - i, tmpc;
      if (abs((c / i) * i - c) < abs((c / i + 1) * i - c)) {
        tmpc = (c / i) * i;
      } else {
        tmpc = (c / i + 1) * i;
      }
      auto it = lower_bound(factor[i].begin(), factor[i].end(), a);
      int tmpa;
      if (it != factor[i].begin()) {
        auto it2 = it - 1;
        if (abs(*it - a) > abs(*it2 - a))
          tmpa = *it2;
        else
          tmpa = *it;
      } else
        tmpa = *it;
      tmp += abs(a - tmpa) + abs(c - tmpc);
      if (tmp < ans) {
        ans = tmp;
        ansA = tmpa, ansB = i, ansC = tmpc;
      }
    }
    for (int i = b; i <= 12000; i++) {
      if (i - b > ans) break;
      int tmp = i - b, tmpc;
      if (abs((c / i) * i - c) < abs((c / i + 1) * i - c)) {
        tmpc = (c / i) * i;
      } else {
        tmpc = (c / i + 1) * i;
      }
      auto it = lower_bound(factor[i].begin(), factor[i].end(), a);
      int tmpa;
      if (it != factor[i].begin()) {
        auto it2 = it - 1;
        if (abs(*it - a) > abs(*it2 - a))
          tmpa = *it2;
        else
          tmpa = *it;
      } else
        tmpa = *it;
      tmp += abs(a - tmpa) + abs(c - tmpc);
      if (tmp < ans) {
        ans = tmp;
        ansA = tmpa, ansB = i, ansC = tmpc;
      }
    }
    cout << ans << endl;
    cout << ansA << " " << ansB << " " << ansC << endl;
  }
}
