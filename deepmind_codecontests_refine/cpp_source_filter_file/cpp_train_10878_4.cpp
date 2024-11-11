#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<bool> in(1 << 20);
  vector<int> sum(n + 1);
  for (int i = 0; i < n; ++i) {
    char c;
    int r;
    cin >> c >> r;
    if (c == '+') {
      in[r] = true;
      sum[i] = 1;
    } else if (!in[r] && c == '-') {
      sum[0] += 1;
      sum[i + 1] -= 1;
    } else {
      sum[i + 1] -= 1;
      in[r] = false;
    }
  }
  for (int i = 0; i < n; ++i) {
    sum[i + 1] += sum[i];
  }
  cout << *max_element(begin(sum), end(sum)) << endl;
}
