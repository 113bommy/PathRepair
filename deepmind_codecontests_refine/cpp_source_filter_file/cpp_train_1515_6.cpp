#include <bits/stdc++.h>
using namespace std;
map<int, int> in;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long sum = 0;
  for (int i = 0; i < 5; i++) {
    int x;
    cin >> x;
    in[-x]++;
    sum += x;
  }
  long long sol = LLONG_MAX;
  for (auto it = in.begin(); it != in.end(); it++) {
    if (it->second >= 2) {
      sol = min(sol, sum + min(3, it->second) * it->first);
    }
  }
  cout << sol;
  return 0;
}
