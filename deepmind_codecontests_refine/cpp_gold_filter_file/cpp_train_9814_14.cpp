#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
long long qp(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long z = qp(x, y / 2);
  z = z * z % 1000000007;
  if (y & 1) z = z * x % 1000000007;
  return z;
}
long long ans = 0.232524231925e18, a[5222], dp[2][5222];
vector<long long> the_all_num_in_the_arr_push_in_the_vector;
int main() {
  ios::sync_with_stdio(false);
  ;
  long long n;
  cin >> n;
  long long i;
  for (i = 1; i <= n; i++)
    cin >> a[i], the_all_num_in_the_arr_push_in_the_vector.push_back(a[i]);
  stable_sort((the_all_num_in_the_arr_push_in_the_vector).begin(),
              (the_all_num_in_the_arr_push_in_the_vector).end());
  the_all_num_in_the_arr_push_in_the_vector.resize(
      unique(the_all_num_in_the_arr_push_in_the_vector.begin(),
             the_all_num_in_the_arr_push_in_the_vector.end()) -
      the_all_num_in_the_arr_push_in_the_vector.begin());
  memset(dp, 22, sizeof(dp));
  dp[0][0] = 0;
  for (i = 1; i <= n; i++) {
    long long j;
    long long cur = ans;
    for (j = 0; j < the_all_num_in_the_arr_push_in_the_vector.size(); j++) {
      cur = min(cur, dp[i - 1 & 1][j]);
      dp[i & 1][j] =
          cur + abs(the_all_num_in_the_arr_push_in_the_vector[j] - a[i]);
    }
  }
  for (i = 0; i < the_all_num_in_the_arr_push_in_the_vector.size(); i++)
    ans = min(ans, dp[n & 1][i]);
  cout << ans << endl;
  return 0;
}
