#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool check(int x, int y) { return x >= 0 && y >= 0 && x <= 2000 && y <= 2000; }
int fun() {
  static int num = 16;
  return num--;
}
long long exp(long long a, long long p, long long m) {
  if (p == 0) return 1LL;
  if (p == 1) return a;
  long long h = exp(a, p / 2, m);
  h = (h * h) % m;
  if (p & 1) h = (h * a) % m;
  return h;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  int arr[6][6];
  memset(arr, 0, sizeof(arr));
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    arr[a][b] = 1;
    arr[b][a] = 1;
  }
  int f = 0;
  for (long long i = 1; i <= 5; i++) {
    for (long long j = i + 1; j <= 5; j++) {
      for (long long k = i + 1; k <= 5; k++) {
        if (arr[i][j] == 1 && arr[i][k] == 1 && arr[j][k] == 1) f++;
        if (arr[i][j] == 0 && arr[i][k] == 0 && arr[j][k] == 0) f++;
      }
    }
  }
  if (f)
    cout << "WIN";
  else
    cout << "FAIL";
  cout << endl;
}
