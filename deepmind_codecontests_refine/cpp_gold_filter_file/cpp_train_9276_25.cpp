#include <bits/stdc++.h>
using namespace std;
long long n, k;
string s;
long long stop[100][100], freq[101];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long a, b;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    for (int j = 0; j < k; ++j) cin >> stop[i][j], freq[stop[i][j]]++;
  }
  for (int i = 1; i <= 100; ++i)
    if (freq[i] == n) cout << i << " ";
  return 0;
}
