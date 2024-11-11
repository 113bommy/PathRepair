#include <bits/stdc++.h>
using namespace std;
inline long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long inversemod(long long a, long long M) {
  return bigmod(a, M - 2, M);
}
inline long long gcd(long long a, long long b) {
  while (b > 0) {
    a = a % b;
    a ^= b;
    b ^= a;
    a ^= b;
    ;
  }
  return a;
}
inline long long lcm(long long m, long long n) { return m * n / gcd(m, n); }
void Main() {
  long long n, k, arr[555], A, B, winner, prev_winner;
  cin >> n >> k;
  long long mx = 0;
  deque<long long> deq;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    deq.push_back(arr[i]);
    mx = max(mx, arr[i]);
  }
  if (k >= n - 1)
    cout << mx;
  else {
    A = deq.front();
    deq.pop_front();
    B = deq.front();
    deq.pop_front();
    if (A > B) {
      winner = A;
      deq.push_front(A);
      deq.push_back(B);
    } else {
      winner = B;
      deq.push_front(B);
      deq.push_back(A);
    }
    prev_winner = winner;
    for (long long wins = 1; wins < k; wins++) {
      A = deq.front();
      deq.pop_front();
      B = deq.front();
      deq.pop_front();
      if (A > B) {
        winner = A;
        deq.push_front(A);
        deq.push_back(B);
      } else {
        winner = B;
        deq.push_front(B);
        deq.push_back(A);
      }
      if (prev_winner != winner) wins = 0;
      prev_winner = winner;
    }
    cout << winner;
  }
}
int main() {
  Main();
  return 0;
}
