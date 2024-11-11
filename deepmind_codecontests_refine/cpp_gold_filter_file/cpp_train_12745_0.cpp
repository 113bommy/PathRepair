#include <bits/stdc++.h>
using namespace std;
int getBit(int num, int pos) { return (num >> pos) & 1; }
int setBit(int num, int pos, int val) {
  if (val == 0) {
    return num & (~(1 << pos));
  } else {
    return num | (1 << pos);
  }
}
int main() {
  int n, p, k;
  cin >> n >> p >> k;
  if (p - k > 1) cout << "<< ";
  for (int i = p - k; i <= p + k; i++) {
    if (i == p)
      cout << "(" << i << ") ";
    else if (i >= 1 && i <= n)
      cout << i << " ";
  }
  if (p + k < n) cout << ">>";
}
