#include <bits/stdc++.h>
using namespace std;
long long int i, j, ft;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int n;
  cin >> n;
  vector<long long int> de(n + 1, 0);
  for (i = 0; i < (n); i++) {
    long long int t;
    cin >> t;
    de[t]++;
    de[i + 1]++;
  }
  long long int count = 0;
  for (i = 0; i < (n); i++) {
    if (de[i + 1] == 1) count++;
  }
  cout << count << "\n";
  return 0;
}
