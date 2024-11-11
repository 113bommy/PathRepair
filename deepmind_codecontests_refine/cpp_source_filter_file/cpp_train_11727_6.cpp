#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  getline(cin, s);
  getline(cin, t);
  int Q;
  cin >> Q;
  int a, b, c, d;
  vector<int> snuma(s.size() + 1, 0);
  vector<int> snumb(s.size() + 1, 0);
  vector<int> tnuma(t.size() + 1, 0);
  vector<int> tnumb(t.size() + 1, 0);
  for (int i = 1; i < s.size() + 1; i++) {
    snuma[i] = snuma[i - 1];
    snumb[i] = snumb[i - 1];
    if (s[i - 1] == 'A') {
      snuma[i]++;
    } else {
      snumb[i]++;
      snuma[i] = 0;
    }
  }
  for (int i = 1; i < t.size() + 1; i++) {
    tnuma[i] = tnuma[i - 1];
    tnumb[i] = tnumb[i - 1];
    if (t[i - 1] == 'A') {
      tnuma[i]++;
    } else {
      tnumb[i]++;
      tnuma[i] = 0;
    }
  }
  int snumb1, snumta, tnumb1, tnumta;
  for (int i = 0; i < Q; i++) {
    cin >> a >> b >> c >> d;
    snumb1 = snumb[b] - snumb[a - 1];
    tnumb1 = tnumb[d] - tnumb[c - 1];
    snumta = min((b + 1 - a), snuma[b]);
    tnumta = min((d + 1 - c), tnuma[d]);
    bool possible = true;
    if (snumb1 == tnumb1) {
      possible = (snumta >= tnumta && (snumta - tnumta % 3) == 0);
    } else if (snumb1 > tnumb1) {
      possible = false;
    } else {
      if (snumb1 == 0) {
        possible = tnumta < snumta;
      } else {
        possible = tnumta <= snumta;
      }
      possible = possible && ((tnumb1 - snumb1) % 2 == 0);
    }
    if (possible) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;
}
