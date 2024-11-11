#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, lim, i, j, curr;
  string s;
  cin >> n >> s;
  map<long long int, long long int> last, color;
  lim = 1;
  curr = 1;
  color[0] = 1;
  for (i = 1; i < n; i++) {
    for (j = 1; j < lim + 1; j++) {
      if (s[i] >= s[last[j]]) {
        last[j] = i;
        color[i] = j;
        break;
      }
    }
    if (j == lim + 1) {
      lim++;
      last[lim] = i;
      color[i] = lim;
    }
  }
  cout << lim << endl;
  for (i = 0; i < n; i++) cout << color[i] << " ";
  return 0;
}
