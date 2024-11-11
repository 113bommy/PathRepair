#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
int n, m, k, q;
int a[6] = {
    0,
};
int b[6] = {
    0,
};
int total[6] = {
    0,
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    total[num]++;
    a[num]++;
  }
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    total[num]++;
    b[num]++;
  }
  for (int i = 0; i < n; i++) {
    if (total[i] & 1) {
      cout << -1;
      return 0;
    }
  }
  int aa = 0;
  int bb = 0;
  for (int i = 1; i <= 5; i++) {
    if (a[i] > b[i])
      aa += a[i] - b[i];
    else
      bb += b[i] - a[i];
  }
  if ((aa != bb) || aa & 1) {
    cout << -1;
    return 0;
  }
  cout << aa / 2;
  return 0;
}
