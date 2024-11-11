#include <bits/stdc++.h>
using namespace std;
vector<int> lens;
int main() {
  int n, k;
  cin >> n >> k;
  cin.ignore();
  int llen = 0;
  int bcase = 0;
  int wcase = 0;
  for (int o = 0; o < n + 1; o++) {
    string inp;
    getline(cin, inp);
    if (o != n) lens.push_back((int)(inp.length()));
    llen = (int)(inp.length());
  }
  for (int o = 0; o < n; o++) {
    if (lens[o] <= llen) {
      wcase++;
      if (lens[o] != llen) bcase++;
    }
  }
  bcase += ((bcase) / k) * 5;
  wcase += ((wcase - 1) / k) * 5;
  bcase++;
  cout << bcase << ' ' << wcase;
}
