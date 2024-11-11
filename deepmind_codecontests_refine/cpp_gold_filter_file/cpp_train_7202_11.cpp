#include <bits/stdc++.h>
using namespace std;
vector<long long int> data;
void gen(long long int n) {
  if (n > 10000000000LL) return;
  data.push_back(n);
  gen(n * 10 + 4);
  gen(n * 10 + 7);
}
long long int solve(long long int n) {
  long long int rt = 0;
  for (int i = 1; i < data.size(); i++) {
    if (data[i] <= n) {
      rt += (data[i] - data[i - 1]) * data[i];
    } else {
      rt += (n - data[i - 1]) * data[i];
      break;
    }
  }
  return rt;
}
int main() {
  gen(0);
  sort(data.begin(), data.end());
  long long int l, h;
  cin >> l >> h;
  long long int ans = solve(h) - solve(l - 1);
  cout << ans << endl;
  return 0;
}
