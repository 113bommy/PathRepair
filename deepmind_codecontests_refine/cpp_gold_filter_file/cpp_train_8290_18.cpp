#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
const double eps = 1e-9, Pi = 2 * acos(0);
int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  string s;
  cin >> s;
  map<string, int> make_pair;
  for (int i = 0; i <= 9; i++) {
    string x;
    cin >> x;
    make_pair[x] = i;
  }
  for (int i = 0; i < 8; i++) {
    string x = "";
    for (int j = i * 10; j < (i + 1) * 10; j++) x += s[j];
    cout << make_pair[x];
  }
  return 0;
}
