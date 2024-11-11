#include <bits/stdc++.h>
using namespace std;
void print(long long a[], int n) {
  cout << endl;
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}
const int N = 1111;
int db[2][N];
int main() {
  int n, k, x;
  scanf("%d%d%d", &n, &k, &x);
  int minn = 1 << 30;
  int maxx = -minn;
  for (int i = 0; i < n; i++) {
    int r;
    scanf("%d", &r);
    db[0][r]++;
  }
  int b = 0;
  int p = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < N; j++) db[p][j] = 0;
    int c = 0;
    for (int j = 0; j < N; j++) {
      if (db[b][j]) {
        int t = db[b][j];
        if (c % 2 == 0) {
          db[p][j] += t / 2;
          db[p][j ^ x] += (t + 1) / 2;
        } else {
          db[p][j] += (t + 1) / 2;
          db[p][j ^ x] += t / 2;
        }
        c += t;
      }
    }
    swap(b, p);
  }
  for (int i = 0; i < N; i++) {
    if (db[b][i]) {
      minn = min(minn, i);
      maxx = max(maxx, i);
    }
  }
  cout << maxx << " " << minn << endl;
  return 0;
}
