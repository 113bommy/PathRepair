#include <bits/stdc++.h>
using namespace std;
long long int expo_fast(long long int a, long long int b) {
  a = a;
  long long int result = 1;
  while (b) {
    if (b & 1) result = (result * a);
    b >>= 1;
    a = (a * a);
  }
  return (result);
}
void take_in(vector<long long int>* arr) {
  for (int i = 0; i < arr->size(); i++) cin >> (*(arr))[i];
}
void disp_arr(vector<long long int>* arr) {
  for (int i = 0; i < arr->size(); i++) cout << (*(arr))[i] << " ";
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> b[i][j];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (a[i][j] != b[i][j]) {
        a[i][j] ^= 1;
        a[i][j + 1] ^= 1;
        a[i + 1][j] ^= 1;
        a[i + 1][j + 1] ^= 1;
      }
    }
  }
  bool crap = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != b[i][j]) {
        cout << "NO\n";
        crap = true;
        break;
      }
    }
  }
  if (!crap) cout << "YES";
}
