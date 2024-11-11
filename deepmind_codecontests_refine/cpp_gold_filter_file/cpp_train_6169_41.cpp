#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 205;
const long long int mod = 1e9 + 7;
vector<long long int> tr[MAXN];
bool vis[MAXN];
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 4)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
