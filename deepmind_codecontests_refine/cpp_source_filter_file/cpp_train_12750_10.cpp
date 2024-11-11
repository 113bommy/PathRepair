#include <bits/stdc++.h>
using namespace std;
char _;
string a;
int i, arr[10], n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> a;
  for (i = 0; i < n; ++i) {
    int ch = a[i] - '0';
    if (ch == 4)
      arr[2] += 2, arr[3]++;
    else if (ch == 6)
      arr[5]++, arr[3]++;
    else if (ch == 8)
      arr[7]++, arr[2] += 4;
    else if (ch == 9)
      arr[7]++, arr[2] += 2, arr[3] += 2;
    else
      arr[ch]++;
  }
  for (i = 9; i >= 2; --i) cout << string(arr[i], i + '0');
  cout << endl;
}
