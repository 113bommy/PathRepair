#include <bits/stdc++.h>
using namespace std;
vector<long long int> mini, maxi;
int main() {
  long long int t, n, minipos, maxpos, i;
  char c;
  cin >> t;
  while (t--) {
    mini.clear();
    maxi.clear();
    cin >> n;
    for (i = 1; i <= n; i++) {
      if (i + 1 > n) break;
      cout << "? " << i << " " << i + 1 << "\n";
      fflush(stdout);
      cin >> c;
      if (c == '>') {
        mini.push_back(i + 1);
        maxi.push_back(i);
      } else {
        mini.push_back(i);
        maxi.push_back(i + 1);
      }
      i += 2;
    }
    if (n % 2 == 1) {
      mini.push_back(n);
      maxi.push_back(n);
    }
    minipos = mini[0];
    for (i = 1; i < mini.size(); i++) {
      cout << "? " << minipos << " " << mini[i] << "\n";
      fflush(stdout);
      cin >> c;
      if (c == '>') minipos = mini[i];
    }
    maxpos = maxi[0];
    for (i = 1; i < maxi.size(); i++) {
      cout << "? " << maxpos << " " << maxi[i] << "\n";
      fflush(stdout);
      cin >> c;
      if (c == '<') maxpos = maxi[i];
    }
    cout << "! " << minipos << " " << maxpos << "\n";
    fflush(stdout);
  }
  return 0;
}
