#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
template <typename T>
void printV(vector<T>& v) {
  for (int i = 0; i < (int)(v.size()); i++) cout << v[i] << " ";
  cout << endl;
}
template <typename T>
void printVs(vector<vector<T> >& v) {
  for (int i = 0; i < (int)(v.size()); i++) printV(v[i]);
}
template <typename T>
void printVs(T** v, int H, int W) {
  for (int i = 0; i < (int)(H); i++) {
    for (int j = 0; j < (int)(W); j++) cout << v[i][j] << " ";
    cout << endl;
  }
}
void printV(vector<pair<int, int> >& v) {
  for (int i = 0; i < (int)(v.size()); i++)
    cout << "(" << v[i].first << "," << v[i].second << ") ";
}
void err() { cout << "wtf " << endl; }
int main() {
  long long A[3];
  for (int i = 0; i < (int)(3); i++) cin >> A[i];
  long long sm = 0;
  long long mx = 1LL << 32;
  long long res = mx;
  for (int i = 0; i < (int)(3); i++)
    for (int j = (i + 1); j < (int)(3); j++)
      if ((A[i] + A[j]) % 2 == 0) res = min(res, max(A[i], A[j]));
  cout << (res == mx ? -1 : res) << endl;
}
