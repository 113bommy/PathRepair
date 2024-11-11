#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
void input();
vector<int> prime;
bitset<100005> bs;
void sieve() {
  bs.set();
  for (int i = 2; i <= n; i++) {
    if (bs[i]) {
      prime.push_back(i);
      for (int j = i + i; j <= n; j += i) {
        bs[j] = 0;
      }
    }
  }
}
void solve() {
  sieve();
  for (int i = 0; i < prime.size(); i++) {
    int pw = prime[i];
    while (pw <= n) {
      ans.push_back(pw);
      pw *= prime[i];
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
int main() {
  input();
  solve();
}
void input() { cin >> n; }
