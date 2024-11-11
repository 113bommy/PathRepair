#include <bits/stdc++.h>
using namespace std;
int a[1010], n, k;
int b[1010];
vector<int> v;
bool search(int nn, int kk, int min) {
  if (nn == 0) return true;
  if (kk <= 0) return false;
  for (int i = min; i < v.size() && v[i] <= nn; i++) {
    if (search(nn - v[i], kk - 1, i)) {
      return true;
    }
  }
  return false;
}
int main() {
  v.push_back(2);
  for (int i = 3; i < 1010; i += 2) {
    if (a[i] == 0) {
      v.push_back(i);
      for (int j = i * 3; j < 1010; j += i * 2) {
        a[j] = 1;
      }
    }
  }
  for (int i = 0; i < v.size() - 1 && v[i] + v[i + 1] + 1 <= 1000; i++) {
    b[v[i] + v[i + 1] + 1] = 1;
  }
  cin >> n >> k;
  int cnt = 0;
  for (int i = 3; i <= n; i++) {
    if (b[i] && a[i] == 0) cnt++;
  }
  if (cnt >= k) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
