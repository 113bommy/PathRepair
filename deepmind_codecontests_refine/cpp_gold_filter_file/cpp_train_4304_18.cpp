#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
int nomalDay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leapDay[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int OHT = 100100;
const int TH = 1010;
const int FH = 510;
const int MAXINF = (2 << 26);
const int MININF = (~(2 << 26));
const double PI = 3.1415926535897932384626433832795;
struct node {
  int x, y;
};
inline bool upcmp(int a, int b) { return a < b; }
inline bool downcmp(int a, int b) { return a > b; }
inline int getbits(int n) { return n == 0 ? 1 : (int)log10(n) + 1; }
int num[100000];
int main() {
  long long a, res;
  cin >> a;
  res = 12 * (a - 1) + ((a - 1) * (a - 2) * 12) / 2;
  cout << res + 1 << endl;
  return 0;
}
