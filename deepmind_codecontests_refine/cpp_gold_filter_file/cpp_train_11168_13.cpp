#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1e9;
vector<long long> v1[1000007];
vector<long long> dis1[1000007];
long long vis[1000007];
long long in[100007];
bool flag = true;
char ch[1007][1007];
long long dx[8] = {0, +1, -1, 0, -1, +1, -1, +1};
long long dy[8] = {+1, 0, 0, -1, -1, +1, +1, -1};
long long low[100007];
long long par[100007];
long long dp[3007][3007];
bool prime[1000007];
long long cache[2017][2017];
long long n, ans = 0, m, sum = 0, k;
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  sum = 0;
  vector<long long> find(n + 1);
  vector<long long> v;
  for (long long i = 0; i < n - 1; i++) {
    cout << "? " << 1 << ' ' << i + 2 << endl;
    cin >> k;
    v.push_back(k);
  }
  cout << "? " << 2 << ' ' << 3 << endl;
  cin >> k;
  v.push_back(k);
  find[3] = v[1] - v[0];
  find[2] = v[n - 1] - find[3];
  find[1] = v[0] - find[2];
  sum = find[1] + find[2] + find[3];
  for (long long i = 2; i < v.size() - 1; i++) {
    find[i + 2] = v[i] - sum;
    sum += find[i + 2];
  }
  cout << "! ";
  for (long long i = 1; i <= n; i++) cout << find[i] << ' ';
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  ;
  return 0;
}
