#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
const int MAX = 100005;
int isprime[MAX];
int a[MAX];
int ans[100005];
vector<int> factor[MAX];
void get_prime() {
  memset(isprime, 0, sizeof(isprime));
  for (int i = 2; i < MAX; i++) {
    if (isprime[i] >= 0) {
      prime.push_back(i);
      isprime[i] = prime.size() - 1;
      factor[i].push_back(i);
      for (int j = 2 * i; j < MAX; j += i) {
        factor[j].push_back(i);
        isprime[j] = -1;
      }
    }
  }
}
int main() {
  get_prime();
  int n;
  while (cin >> n) {
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      int m = 0;
      for (int j = 0; j < factor[a[i]].size(); j++)
        m = max(ans[factor[a[i]][j]] + 1, m);
      for (int j = 0; j < factor[a[i]].size(); j++) ans[factor[a[i]][j]] = m;
    }
    int M = 1;
    for (int i = 0; i < 10000; i++) M = max(M, ans[i]);
    cout << M << endl;
  }
  return 0;
}
