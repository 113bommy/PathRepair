#include <bits/stdc++.h>
using namespace std;
long long int a, b;
vector<long long int> v;
void backtrack(long long int n) {
  if (n > 10000000009) return;
  if (n >= a) {
    v.push_back(n);
  }
  backtrack(n * 10 + 4);
  backtrack(n * 10 + 7);
}
int main() {
  long long int n, i, j, k;
  cin >> a >> b;
  backtrack(0);
  sort(v.begin(), v.end());
  unsigned long long int sum = 0;
  for (i = 0; i < v.size(); i++) {
    sum = sum + v[i] * (min(v[i], b) - a + 1);
    a = v[i] + 1;
    if (a > b) break;
  }
  cout << sum << endl;
  return 0;
}
