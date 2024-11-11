#include <bits/stdc++.h>
using namespace std;
void edit(vector<int> &skill, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    skill.push_back(x);
  }
}
void achilles() {
  long long x, y, a, b;
  cin >> x >> y >> a >> b;
  float n = (float)(y - x) / (float)(a + b);
  if (n > 0 && ((long long)n == n))
    cout << n << "\n";
  else
    cout << "-1\n";
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) achilles();
  return 0;
}
