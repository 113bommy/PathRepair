#include <bits/stdc++.h>
using namespace std;
string a;
int lens[1001];
int main() {
  int n, k, min1 = 0, max1 = 0, len, cur, i;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a;
    lens[i] = a.size();
  }
  cin >> a;
  len = a.size();
  sort(lens, lens + n);
  cur = 0;
  for (i = 0; i < n; i++) {
    if (lens[i] == len) {
      min1++;
      break;
    }
    min1++;
    cur++;
    if (cur == k) min1 += 5, cur = 0;
  }
  cur = 0;
  for (i = 0; i < n; i++) {
    if ((i == n - 1) || (lens[i + 1] > len)) {
      max1++;
      break;
    }
    max1++;
    cur++;
    if (cur == k) max1 += 5, cur = 0;
  }
  cout << min1 << " " << max1;
  cout << endl;
  return 0;
}
