#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > vvi;
int main() {
  int N;
  cin >> N;
  int ans = 1 + N / 2;
  cout << ans << endl;
  int n = 0;
  for (int i = 0, j = 1, n = 0; n < N; n++) {
    if (n % 2 == 0) {
      i++;
      cout << i << " " << j << endl;
    } else {
      j++;
      cout << i << " " << j << endl;
    }
  }
  return 0;
}
