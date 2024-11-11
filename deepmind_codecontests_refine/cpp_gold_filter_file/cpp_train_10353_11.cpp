#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, sum = 0;
  long long v, temp;
  cin >> n >> v;
  bool seller[51] = {0};
  for (int i = 0; i < n; i++) {
    cin >> k;
    bool f = false;
    for (int j = 0; j < k; j++) {
      cin >> temp;
      if (temp < v && !f) {
        sum++;
        seller[i + 1] = 1;
        f = true;
      }
    }
  }
  cout << sum << "\n";
  if (sum != 0) {
    for (int i = 0; i < 51; i++)
      if (seller[i]) cout << i << " ";
  }
  return 0;
}
