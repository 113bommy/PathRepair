#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void gen(long long x) {
  if (x > (int)(1e9)) return;
  v.push_back(x);
  gen(x * 10 + 4);
  gen(x * 10 + 7);
}
int main() {
  gen(0);
  int n;
  cin >> n;
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (v[i] >= n) {
      cout << i << "\n";
      break;
    }
  }
}
