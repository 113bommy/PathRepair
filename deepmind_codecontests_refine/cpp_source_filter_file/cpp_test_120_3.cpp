#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> b(200003, vector<int>(20));
void calc() {
  for (int i = 1; i < 200002; i++) {
    int num = i;
    int curr = 0;
    while (num > 0) {
      b[i][curr] = num % 2 + b[i - 1][curr];
      num /= 2;
      curr++;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, l, r;
  cin >> t;
  calc();
  while (t--) {
    cin >> l >> r;
    int n = r - l + 1;
    int maxi = 0;
    for (int i = 0; i < 20; i++) {
      maxi = max(maxi, b[r][i] - b[l][i]);
    }
    cout << n - maxi << endl;
  }
  return 0;
}
