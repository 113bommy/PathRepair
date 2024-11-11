#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
long long ans = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long black = 0, white = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i % 2 == 0)
      black += x / 2, white += x - x / 2;
    else
      white += x / 2, black += x - x / 2;
  }
  cout << min(black, white);
  return 0;
}
