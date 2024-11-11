#include <bits/stdc++.h>
using namespace std;
long long readi() {
  long long input = 0;
  char c = ' ';
  while (c < '-') {
    c = getchar();
  }
  bool negative = false;
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  while (c >= '0') {
    input = 10 * input + (c - '0');
    c = getchar();
  }
  if (negative) {
    input = -input;
  }
  return input;
}
string reads() {
  string input = "";
  char c = ' ';
  while (c <= ' ') {
    c = getchar();
  }
  while (c > ' ') {
    input += c;
    c = getchar();
  }
  return input;
}
void printi(long long output) {
  if (output == 0) {
    putchar('0');
    return;
  }
  if (output < 0) {
    putchar('-');
    output = -output;
  }
  vector<char> vout;
  while (output) {
    vout.push_back((output % 10) + '0');
    output /= 10;
  }
  for (int i = vout.size() - 1; i >= 0; i--) {
    putchar(vout[i]);
  }
  return;
}
void prints(string output) {
  for (int i = 0; i < output.length(); i++) {
    putchar(output[i]);
  }
  return;
}
long long N;
int arr[100010];
long long tree[100010];
long double ans;
long long p;
void update(int idx, long long val) {
  for (int e = idx + 1; e <= N; e += e & (-e)) {
    tree[e] += val;
  }
  return;
}
long long query(int idx) {
  long long res = 0;
  for (int e = idx + 1; e > 0; e -= e & (-e)) {
    res += tree[e];
  }
  return res;
}
int32_t main() {
  cout << fixed << setprecision(10);
  ios_base::sync_with_stdio(false);
  if (fopen("cf749e.in", "r")) {
    freopen("cf749e.in", "r", stdin);
    freopen("cf749e.out", "w", stdout);
  }
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    arr[i] = N - arr[i];
  }
  ans = (long double)((N + 2) * (N - 1)) / 24.0;
  for (int i = 0; i < N; i++) {
    p += (long double)query(arr[i] - 1);
    update(arr[i], 1);
  }
  ans += p;
  p = 0;
  for (int i = 0; i <= N; i++) {
    tree[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    p += (N - i) * query(arr[i] - 1);
    update(arr[i], i + 1);
  }
  p *= 2;
  ans -= (((long double)p) / ((long double)(N * (N + 1))));
  cout << ans << '\n';
  return 0;
}
