#include <bits/stdc++.h>
using namespace std;
void anamika() {
  int n, i = -1, j = -1, k = -1, l = -1;
  string str;
  cin >> n >> str;
  i = str.find('R');
  if (i == -1) {
    k = str.find('L');
    l = str.rfind('L');
    cout << l + 1 << " " << k;
    return;
  }
  j = str.find('L');
  if (j == -1) {
    l = str.find('R');
    k = str.rfind('R');
    cout << l + 1 << " " << k + 2;
    return;
  }
  cout << i + 1 << " " << j;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) anamika();
}
