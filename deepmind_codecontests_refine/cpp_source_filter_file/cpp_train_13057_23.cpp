#include <bits/stdc++.h>
using namespace std;
int ans;
int arr[10000];
string s;
void makemat(int r, int c) {
  int k = 0;
  char ch[r][c];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      ch[i][j] = s[k++];
    }
  }
  for (int i = 0; i < c; i++) {
    int f = 0;
    for (int j = 0; j < r; j++) {
      if (ch[j][i] == 'O') {
        f = 1;
        break;
      }
    }
    if (f == 0) {
      arr[ans * 2] = r;
      arr[ans * 2 + 1] = c;
      ans++;
      return;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> s;
    makemat(1, 12);
    makemat(2, 6);
    makemat(3, 4);
    makemat(4, 3);
    makemat(6, 2);
    makemat(12, 1);
    cout << ans << " ";
    for (int i = 0; i < ans; i++) {
      cout << arr[2 * i] << "*" << arr[2 * i + 1] << " ";
    }
    cout << endl;
  }
}
