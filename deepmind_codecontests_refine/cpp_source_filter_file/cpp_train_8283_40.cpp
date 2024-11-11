#include <bits/stdc++.h>
using namespace std;
void init() {}
const int N = (int)1e7 + 34;
const long long M = (long long)1e9 + 34;
string R = "0101000?_10?_01_";
string q = "0100000011001010";
string t = "0101000011001011";
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = a * 8 + b * 4 + c * 2 + d;
  cout << t[x];
  return 0;
}
