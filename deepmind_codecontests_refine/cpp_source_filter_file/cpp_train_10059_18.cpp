#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
const long long inf = 2147383647;
const long long mod = 1e9 + 7;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
const int Size = 5000;
int aSum[Size + 10];
int bSum[Size + 10];
string line;
int len;
int solve() {
  int result = 0;
  for (int i = 1; i <= len; i++) {
    int tmpA = aSum[i];
    for (int j = i + 1; j <= len; j++) {
      int tmpB = (bSum[j] - bSum[i]);
      int tmpAA = (aSum[len] - aSum[j]);
      int tmpResult = tmpA + tmpB + tmpAA;
      if (tmpResult > result) result = tmpResult;
    }
  }
  return result;
}
int main() {
  cin >> line;
  int aCnt = 0, bCnt = 0;
  memset(aSum, 0, sizeof aSum);
  memset(bSum, 0, sizeof bSum);
  len = line.size();
  for (int i = 0; i < len; i++) {
    if (line[i] == 'a') {
      aCnt++;
      aSum[i + 1] = (aSum[i] + 1);
      bSum[i + 1] = bSum[i];
    } else if (line[i] == 'b') {
      bCnt++;
      bSum[i + 1] = (bSum[i] + 1);
      aSum[i + 1] = aSum[i];
    }
  }
  int res = solve();
  res = ((res) > (((aCnt) > (bCnt) ? (aCnt) : (bCnt)))
             ? (res)
             : (((aCnt) > (bCnt) ? (aCnt) : (bCnt))));
  cout << res << endl;
  return 0;
}
