#include <bits/stdc++.h>
using namespace std;
int arr[110];
int src[30][110][110];
int temp[110][110];
int dst[110][110];
int add(int a, int b) { return (a + b) % 1000000007; }
int sub(int a, int b) { return (a - b + 1000000007) % 1000000007; }
int prod(int a, int b) { return 1LL * a * b % 1000000007; }
int power(int a, int n) {
  if (!n) return 1;
  int mid = power(a, n / 2);
  mid = prod(mid, mid);
  if (n % 2) mid = prod(mid, a);
  return mid;
}
int inv(int a) { return power(a, 1000000007 - 2); }
void matmul(int a[110][110], int b[110][110], int c[110][110], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp[i][j] = 0;
      for (int k = 0; k < n; k++)
        temp[i][j] = add(temp[i][j], prod(a[i][k], b[k][j]));
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) c[i][j] = temp[i][j];
  }
}
void matPower(int k, int n) {
  for (int i = 1; i < 30; i++) matmul(src[i - 1], src[i - 1], src[i], n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) dst[i][j] = (i == j);
  }
  for (int i = 0; i < 30; i++) {
    if (k & (1 << i)) matmul(dst, src[i], dst, n);
  }
}
int main(void) {
  int N, K, cnt, C;
  cin >> N >> K;
  C = 0;
  cnt = 0;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (!arr[i]) cnt++;
  }
  for (int i = 0; i < cnt; i++) C += !arr[i];
  for (int i = max(0, 2 * cnt - N); i <= cnt; i++) {
    src[0][i][i] = 1;
    if (i > max(0, 2 * cnt - N)) {
      src[0][i][i - 1] = prod(inv(N * (N - 1) / 2), i * (N + i - cnt - cnt));
      src[0][i][i] = sub(src[0][i][i], src[0][i][i - 1]);
    }
    if (i < cnt) {
      src[0][i][i + 1] = prod(inv(N * (N - 1) / 2), (cnt - i) * (cnt - i));
      src[0][i][i] = sub(src[0][i][i], src[0][i][i + 1]);
    }
  }
  for (int i = max(0, 2 * cnt - N); i <= cnt; i++) {
    for (int j = max(0, 2 * cnt - N); j <= cnt; j++)
      src[0][i - max(0, 2 * cnt - N)][j - max(0, 2 * cnt - N)] = src[0][i][j];
  }
  C -= max(0, 2 * cnt - N);
  cnt -= max(0, 2 * cnt - N);
  matPower(cnt + 1, K);
  cout << dst[C][cnt] << endl;
  return 0;
}
