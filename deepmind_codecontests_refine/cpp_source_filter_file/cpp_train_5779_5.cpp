#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
bool visit[maxn];
vector<int> prime;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, i, j;
  cin >> n;
  if (n == 3) {
    cout << 1 << "\n" << 3;
    return 0;
  }
  if (n == 5) {
    cout << 2 << "\n" << 2 << " " << 3;
    return 0;
  }
  visit[0] = true;
  visit[1] = true;
  for (i = 2; i < maxn; i++) {
    if (!visit[i]) {
      prime.push_back(i);
      for (j = i + i; j < maxn; j += i) visit[j] = true;
    }
  }
  if (n < maxn && !visit[n]) {
    cout << "1\n" << n;
    return 0;
  }
  int pp = 3;
  if (n > 50000) {
    for (i = n; i >= n - 5000; i--) {
      if (i % 2 == 0) continue;
      for (j = 1; j < int(prime.size()); j++)
        if (i % prime[j] == 0) break;
      if (j == int(prime.size())) {
        pp = i;
        n -= pp;
        break;
      }
    }
    if (n == 0) cout << "1\n" << pp;
    if (n == 2) cout << "2\n2 " << pp;
  } else {
    n = n - 3;
    pp = 3;
  }
  for (i = 3; i < maxn; i++) {
    if (!visit[i]) {
      if (n - i >= 0 && !visit[n - i]) {
        cout << "3\n" << pp << " " << i << " " << n - i;
        return 0;
      }
    }
  }
  return 0;
}
