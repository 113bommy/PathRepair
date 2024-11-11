#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> give(n, 0), received(n, 0);
  for (int i = 1; i <= n; i++) {
    cin >> give[i];
    received[give[i]] = i;
  }
  for (int i = 1; i <= n; i++) cout << received[i] << " ";
}
