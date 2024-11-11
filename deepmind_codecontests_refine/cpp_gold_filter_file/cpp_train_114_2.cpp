#include <bits/stdc++.h>
using namespace std;
string hexc(char c) {
  if (c == '0') return "0000";
  if (c == '1') return "0001";
  if (c == '2') return "0010";
  if (c == '3') return "0011";
  if (c == '4') return "0100";
  if (c == '5') return "0101";
  if (c == '6') return "0110";
  if (c == '7') return "0111";
  if (c == '8') return "1000";
  if (c == '9') return "1001";
  if (c == 'A') return "1010";
  if (c == 'B') return "1011";
  if (c == 'C') return "1100";
  if (c == 'D') return "1101";
  if (c == 'E') return "1110";
  return "1111";
}
bool rowisfine(string row, long long mod, long long n) {
  vector<string> bins(n / 4);
  for (long long i = 0; i < n / 4; ++i) {
    bins[i] = hexc(row[i]);
  }
  for (long long i = 0; i < n / mod; ++i) {
    char c = bins[i * mod / 4][i * mod % 4];
    for (long long j = 1; j < mod; ++j) {
      long long curi = i * mod + j;
      if (bins[curi / 4][curi % 4] != c) return false;
    }
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long cols = n / 4;
  vector<string> s(n);
  for (long long i = 0; i < n; ++i) cin >> s[i];
  bool done = false;
  for (long long i = n; i >= 2; --i) {
    if (n % i) continue;
    long long row;
    for (row = 0; row < n; ++row) {
      if (row % i == 0) {
        if (!rowisfine(s[row], i, n)) {
          break;
        }
      } else {
        long long col;
        for (col = 0; col < cols; ++col) {
          if (s[row][col] != s[row - 1][col]) break;
        }
        if (col != cols) break;
        ;
      }
    }
    if (row == n) {
      done = true;
      cout << i << endl;
      break;
    }
  }
  if (!done) cout << 1 << endl;
  return 0;
}
