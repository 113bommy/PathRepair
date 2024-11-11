#include <bits/stdc++.h>
using namespace std;
long long cntInv[35][2];
void solve(vector<int>& a, int hBit) {
  if (a.size() == 0 || hBit < 0) return;
  int n = a.size();
  int cur0 = 0, cur1 = 0;
  vector<int> bit0, bit1;
  for (int i = 0; i < n; i++) {
    if (a[i] & (1 << hBit)) {
      cur1++;
      cntInv[hBit][1] += cur0;
      bit1.push_back(a[i]);
    } else {
      cur0++;
      cntInv[hBit][0] += cur1;
      bit0.push_back(a[i]);
    }
  }
  solve(bit0, hBit - 1);
  solve(bit1, hBit - 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  solve(a, 30);
  int res = 0;
  long long numInv = 0;
  for (int i = 0; i <= 10; i++) {
    int ind = 0;
    if (cntInv[i][0] > cntInv[i][1]) {
      ind = 1;
      res += (1 << i);
    }
    numInv += cntInv[i][ind];
  }
  cout << numInv << " " << res << endl;
  return 0;
}
