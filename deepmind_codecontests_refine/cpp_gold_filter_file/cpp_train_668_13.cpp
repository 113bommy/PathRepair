#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a % b)); }
int LCM(int a, int b) { return a * (b / GCD(a, b)); }
int dx4[] = {-1, 0, 0, 1};
int dy4[] = {0, -1, 1, 0};
int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
string s;
long long PosOdd[3], PosEven[3], even = 0, odd = 0;
int main() {
  getline(cin, s);
  int len = s.length();
  memset(PosEven, 0, sizeof(PosEven));
  memset(PosOdd, 0, sizeof(PosOdd));
  for (int i = 0; i < len; i++) {
    if (i & 1) {
      even += PosEven[s[i] - 'a'];
      odd += PosOdd[s[i] - 'a'];
      PosOdd[s[i] - 'a']++;
    } else {
      even += PosOdd[s[i] - 'a'];
      odd += PosEven[s[i] - 'a'];
      PosEven[s[i] - 'a']++;
    }
  }
  cout << even << " " << odd + len << endl;
  return 0;
}
