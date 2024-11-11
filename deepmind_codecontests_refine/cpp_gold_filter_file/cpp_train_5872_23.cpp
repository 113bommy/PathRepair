#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 5)
    cout << ">...v\nv.<..\n..^..\n>....\n..^.<\n1 1";
  else if (n == 3)
    cout << ">vv\n^<.\n^.<\n1 3";
  else {
    for (int i = 1; i <= 100; ++i) {
      if (i & 1) {
        if (i == 1)
          cout << ">";
        else
          cout << "^";
        for (int j = 2; j <= 34; ++j) cout << ">";
        for (int j = 34; j <= 97; j += 2) {
          cout << ">.";
        }
        cout << "v.";
      } else {
        cout << "^";
        if (i != 100)
          cout << "v<";
        else
          cout << "<<";
        for (int j = 4; j <= 67; j += 2) {
          cout << ".<";
        }
        for (int j = 68; j <= 99; ++j) cout << "<";
        cout << ".";
      }
      cout << "\n";
    }
    cout << "1 1";
  }
}
