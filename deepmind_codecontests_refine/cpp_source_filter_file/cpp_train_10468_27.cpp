#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int BitSetUp(int x, int idx) { return x = x | (1 << idx); }
int BitUnSet(int x, int idx) { return x = x & (~(1 << idx)); }
bool BitCheking(int x, int idx) { return x & (1 << idx); }
bool PowerOfTwo(int x) { return (x && !(x & (x - 1))); }
void DenTofieM() {
  string s;
  cin >> s;
  if (s[0] >= 'b' && s[0] <= 'g' && s[1] >= '2' && s[1] <= '7')
    cout << 8 << "\n";
  else if ((s[0] == 'a' || s[0] == 'h') && (s[1] == '1' || s[1] == '8'))
    cout << 3 << "\n";
  else
    cout << 4 << "\n";
}
int main() {
  DenTofieM();
  return 0;
}
