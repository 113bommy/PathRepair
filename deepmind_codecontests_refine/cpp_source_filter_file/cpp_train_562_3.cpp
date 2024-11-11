#include <bits/stdc++.h>
using namespace std;
template <typename T>
T next_int() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * p;
}
const int max_n = (int)2e5 + 227 + 1;
const int max_int = (int)1e9 + 227 + 1;
const int mod = (int)1e9 + 7;
int main() {
  long long a = next_int<int>();
  long long b = next_int<int>();
  long long first = (long long)-1e18;
  int p = -1;
  for (int i = 1; i <= a; i++) {
    int j = i + 1;
    if (j > b) break;
    long long ans = 0;
    long long t = b / j;
    long long u = b % j;
    ans -= u * (t + 1) * (t + 1);
    ans -= (j - u) * t * t;
    ans += i - 1;
    ans += (a - i + 1) * (a - i + 1);
    if (first < ans) {
      first = ans;
      p = i;
    }
  }
  long long second = a * a - b * b;
  if (first < second) {
    cout << second << "\n";
    for (int i = 0; i < a; i++) cout << "o";
    for (int i = 0; i < b; i++) cout << "x";
  } else {
    cout << first << "\n";
    long long t = b / (p + 1);
    long long u = b % (p + 1);
    if (u) {
      u--;
      cout << "x";
    }
    for (int i = 0; i < t; i++) cout << "x";
    for (int i = 1; i <= p; i++) {
      if (i != p)
        cout << "o";
      else
        for (int i = 0; i <= a - i; i++) cout << "o";
      if (u) {
        u--;
        cout << "x";
      }
      for (int i = 0; i < t; i++) cout << "x";
    }
  }
}
