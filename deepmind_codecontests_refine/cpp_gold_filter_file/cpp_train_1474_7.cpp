#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int Dis[MAXN];
int main() {
  int n, v;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v;
    Dis[v]++;
    if (Dis[v] > 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  vector<int> nor, rev;
  for (int i = 0; i <= 200000; i++)
    if (Dis[i] > 0) nor.push_back(i), Dis[i]--;
  for (int i = 200000; i >= 0; i--)
    if (Dis[i] > 0) rev.push_back(i), Dis[i]--;
  cout << "YES" << endl;
  cout << nor.size() << endl;
  for (auto x : nor) cout << x << ' ';
  cout << endl;
  cout << rev.size() << endl;
  for (auto x : rev) cout << x << ' ';
  cout << endl;
  return 0;
}
