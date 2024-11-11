#include <bits/stdc++.h>
using namespace std;
string line;
int digits[10] = {0};
void start() {
  cin >> line;
  for (int i = 0; i < int(line.size()); ++i) {
    digits[line[i] - '0'] += 1;
  }
  digits[1] -= 1;
  digits[6] -= 1;
  digits[8] -= 1;
  digits[9] -= 1;
  bool allZero = true;
  for (int i = 1; i < int(10); ++i) {
    if (digits[i] != 0) {
      allZero = false;
      break;
    }
  }
  if (allZero) {
    cout << "1869";
    for (int i = 0; i < int(digits[0]); ++i) cout << "0";
    cout << endl;
    return;
  }
  int p[6] = {4, 5, 1, 3, 2, 6};
  int sum = 0;
  int cnt = 0;
  string ret;
  for (int i = 0; i <= 9; ++i) {
    for (int j = 0; j < int(digits[i]); ++j) {
      sum = (sum + i * p[cnt]) % 7;
      cnt = (cnt + 1) % 6;
      ret += char(i + '0');
    }
  }
  reverse(ret.begin(), ret.end());
  int perm[] = {0, 1, 2, 3};
  int res[] = {1, 3, 2, 6};
  int num[] = {1, 6, 8, 9};
  do {
    int cur = sum;
    for (int i = 0; i < int(4); ++i) {
      cur = cur + res[i] * num[perm[i]];
    }
    if (cur % 7 == 0) {
      for (int i = 3; i >= 0; --i) ret += char(num[perm[i]] + '0');
      break;
    }
  } while (next_permutation(perm, perm + 4));
  cout << ret << endl;
}
int main(int argc, char** argv) {
  start();
  return 0;
}
