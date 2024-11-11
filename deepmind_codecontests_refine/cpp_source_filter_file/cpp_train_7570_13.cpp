#include <bits/stdc++.h>
using namespace std;
char c[1001];
vector<int> v;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cin >> c[1];
    cout << c[1];
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 2; i <= n; i++) {
    if (n % i == 0) v.push_back(i);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= v.size() - 1; i++) {
    reverse(c + 1, c + v[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    cout << c[i];
  }
}
