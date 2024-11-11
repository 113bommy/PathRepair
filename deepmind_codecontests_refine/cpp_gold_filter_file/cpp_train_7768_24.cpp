#include <bits/stdc++.h>
const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const long long MXLL = 9223372036854775807;
const int Sz = 1110111;
using namespace std;
inline void Read_rap() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline void randomizer3000() {
  unsigned int seed;
  asm("rdtsc" : "=A"(seed));
  srand(seed);
}
int n, x;
int main() {
  Read_rap();
  cin >> n;
  int len;
  cin >> len;
  int sum = n - 1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum += x;
  }
  if (sum == len)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
