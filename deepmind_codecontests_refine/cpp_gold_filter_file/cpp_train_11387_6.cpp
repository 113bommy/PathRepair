#include <bits/stdc++.h>
using namespace std;
int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diry[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ", ";
  err(++it, args...);
}
int n, m;
const int N = 1e5 + 5;
int fact[N], ar[N];
map<int, int> mp;
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> ar[i];
    mp[ar[i]]++;
  }
  int cnt = 0;
  for (long long i = 0; i < n; i++) {
    int scan;
    cin >> scan;
    cnt += scan == ar[i];
    mp[scan]++;
  }
  cin >> m;
  long long ans = 1;
  for (auto i : mp) {
    for (long long j = 2; j <= i.second; j++) {
      long long temp = j;
      if (temp % 2 == 0 && cnt > 0) {
        temp /= 2;
        cnt--;
      }
      ans = (ans * temp) % m;
    }
  }
  cout << ans;
}
