#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> a;
int main() {
  int n;
  cin >> n;
  N = n;
  a.push_back(0);
  a.push_back(0);
  for (int i = 0; i < (1 << (n + 1)) - 2; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  int m = (1 << (n + 1)) * 2;
  vector<int> b(m, 0);
  int result = 0;
  for (int i = (1 << n) - 1; i >= 1; i--) {
    result += abs(b[i * 2] + a[i * 2] - b[i * 2 + 1] - a[i * 2 + 1]);
    b[i] = max(b[i * 2] + a[i * 2], b[i * 2 + 1] + a[i * 2 + 1]);
  }
  cout << result;
  return 0;
}
