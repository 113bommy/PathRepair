#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
const int MAX = 1e5 + 55;
int x[MAX];
int b[MAX];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mp[b[i]] = i;
  }
  int sum = 0;
  int ind = -1;
  for (int i = 0; i < n; i++) {
    if (ind < mp[x[i]]) {
      ind = mp[x[i]];
    } else {
      sum++;
    }
  }
  cout << sum;
  return 0;
}
