#include <bits/stdc++.h>
using namespace std;
const int MAX_LINE_NUMBER = 100;
int main() {
  int n, r, lineNumber, lineCount[MAX_LINE_NUMBER + 1] = {};
  cin >> n;
  for (int stop = 1; stop <= n; ++stop) {
    cin >> r;
    for (int tram = 1; tram <= r; ++tram) {
      cin >> lineNumber;
      ++lineCount[lineNumber];
    }
  }
  for (int line = 1; line <= MAX_LINE_NUMBER; ++line)
    if (lineCount[line] == n) cout << line << ' ';
  cout << "\b\n";
  return 0;
}
