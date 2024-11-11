#include <bits/stdc++.h>
using namespace std;
long long div_up(long long x, long long y) {
  if (x == 0) return 0;
  return (x - 1) / y + 1;
}
long long max_without_branching(long long a, long long b) {
  return (a + b + abs(a - b)) / 2;
}
string inc_s(string a) {
  string a_1;
  reverse(a.begin(), a.end());
  a_1 = a + '0';
  if (a_1[0] == '9') {
    long long i = 0;
    while (a_1[i] == '9') {
      a_1[i] = '0';
      i++;
    }
    a_1[i]++;
    if (a_1[i] != '1') a_1.erase(a_1.size() - 1, 1);
    reverse(a_1.begin(), a_1.end());
    return a_1;
  } else {
    a[0]++;
    reverse(a.begin(), a.end());
    return a;
  }
}
bool is_prime(long long a) {
  for (long long i = 2; i <= sqrt(a); i++)
    if (a % i == 0) return false;
  return true;
}
long long count_divider(long long b) {
  long long i = 1;
  long long ans = 0;
  for (; i * i < b; i++) {
    if (b % i == 0) ans += 2;
  }
  if (i * i == b) ans++;
  return ans;
}
long long first_prime_divider(long long r) {
  for (long long i = 2; i <= (r); i++)
    if (r % i == 0) return i;
  return -1;
}
string sum_str(string a, string b) {
  if (b.length() > a.length()) swap(a, b);
  int k = b.size() - a.size(), s = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a.size() - i <= b.size())
      a[i] += b[k + i] - '0' + s;
    else
      a[i] += s;
    if (a[i] > '9')
      s = 1, a[i] -= 10;
    else
      s = 0;
  }
  if (s) a = '1' + a;
  return a;
}
int len_num(long long num) {
  int ans = 0;
  do {
    ans++;
  } while (num /= 10);
  return ans;
}
long long sum_from_1_to_N(long long N) { return N * (N + 1) / 2; }
bool on_board(int x, int y, int n, int m) {
  return x >= 0 && y >= 0 && x < n && y < m;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  long long a, b;
  cin >> a >> b;
  while (a && b) {
    if (a >= b * 2) {
      a %= b * 2;
    } else if (b >= a * 2) {
      b %= a * 2;
    } else
      break;
  }
  cout << a << " " << b;
  return 0;
}
