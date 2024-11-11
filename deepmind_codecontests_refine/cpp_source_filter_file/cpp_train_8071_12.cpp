#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int f(string S) {
  map<char, int> bit;
  int size = S.size();
  int num = 0;
  int j;
  long long int count = 1;
  for (int i = 0; i < 64; i++) {
    if ((i >= 0) && (i < 10)) {
      bit[(char)i] = i;
    }
    if ((i >= 10) && (i < 36)) {
      bit[(char)(i + 55)] = i;
    }
    if ((i >= 36) && (i < 62)) {
      bit[(char)(i + 61)] = i;
    }
    if (i == 62) {
      bit['-'] = i;
    } else {
      bit['_'] = i;
    }
  }
  for (int i = 0; i < size; i++) {
    j = bit[S.at(i)];
    for (int k = 0; k < 6; k++, j = j >> 1) {
      if (!(j & 1)) {
        num++;
      }
    }
  }
  for (int i = 0; i < num; i++) {
    count = (count * 3) % MOD;
  }
  return count;
}
int main() {
  string str;
  cin >> str;
  cout << f(str);
}
