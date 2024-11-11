#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, a, b;
  cin >> k >> a >> b;
  string rec;
  cin >> rec;
  int n = rec.size();
  int srednji = n / k;
  int novi = 0;
  if (n < k * a || n > k * b) {
    cout << "No solution";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cout << rec[i];
    if (novi == srednji && k > 1) {
      novi = 0;
      k--;
      cout << "\n";
    } else
      novi++;
  }
  return 0;
}
