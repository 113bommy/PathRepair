#include <bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
long long MOD = 998244353;
int main() {
  string t, w;
  cin >> t >> w;
  int charT[10], charW[10];
  for (int i = 0; i < 10; i++) {
    charT[i] = 0;
    charW[i] = 0;
  }
  for (int i = 0; i < t.length(); i++) {
    charT[t[i] - 48] += 1;
  }
  for (int i = 0; i < w.length(); i++) {
    charW[w[i] - 48] += 1;
  }
  charW[2] += charW[5];
  charW[6] += charW[9];
  charT[2] += charT[5];
  charT[6] += charT[9];
  int minnum = 10000000;
  for (int i = 0; i < 10; i++) {
    if (i != 5 && i != 9 && charT[i] != 0) {
      minnum = min(minnum, charW[i] / charT[i]);
    }
  }
  cout << minnum << "\n";
  return 0;
}
