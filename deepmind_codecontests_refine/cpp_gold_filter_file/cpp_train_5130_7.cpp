#include <bits/stdc++.h>
const int N = 300001;
using namespace std;
string a[N];
int xr = 0;
long long int inv = 0;
void f(vector<vector<int>> &b, int bit) {
  if (bit == -1) return;
  long long int fir = 0;
  vector<vector<int>> nex;
  for (auto &bb : b) {
    int one = 0;
    vector<int> zv, ov;
    for (int ind : bb) {
      if (a[ind][bit] == '1') {
        one++;
        ov.push_back(ind);
      } else {
        fir += one;
        zv.push_back(ind);
      }
    }
    if (!zv.empty()) nex.push_back(zv);
    if (!ov.empty()) nex.push_back(ov);
  }
  long long int sec = 0;
  for (auto &bb : b) {
    int one = 0;
    for (int ind : bb) {
      if (a[ind][bit] == '0') {
        one++;
      } else {
        sec += one;
      }
    }
  }
  if (fir <= sec) {
    inv += fir;
  } else {
    inv += sec;
    xr += 1 << bit;
  }
  f(nex, bit - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int mb = 30;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = string(mb, '0');
    for (int j = 0; j < mb; j++) {
      a[i][j] = (x & (1 << j) ? '1' : '0');
    }
  }
  vector<int> v(n);
  for (int i = 0; i < n; i++) v[i] = i;
  vector<vector<int>> j = {v};
  f(j, mb - 1);
  cout << inv << ' ' << xr;
}
