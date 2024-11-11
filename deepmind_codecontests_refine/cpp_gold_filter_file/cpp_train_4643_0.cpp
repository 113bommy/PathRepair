#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int sum, suf, pre, max;
} Node;
int toint(const string &s) {
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}
const int N = 1e5 + 10;
const int MAXN = 3010;
const int UP = 31;
const int lim = 1e18 + 1;
const long long int mod = 1e9 + 7;
const long long int highest = 1e18;
const double pi = acos(-1);
const double Phi = 1.618033988749894;
const int logn = 20;
const double phi = 0.618033988749894;
const double root5 = 2.236067977;
int main() {
  char str[N];
  char suf[N];
  scanf("%s", str + 1);
  stack<char> st;
  int n = strlen(str + 1);
  suf[n] = str[n];
  for (int i = n - 1; i >= 1; --i) {
    suf[i] = min(str[i], suf[i + 1]);
  }
  int ptr = 1;
  while (!st.empty()) {
    st.pop();
  }
  for (int i = 1; i <= n; ++i) {
    if (ptr > n) {
      printf("%c", st.top());
      st.pop();
    } else if (!st.empty() && st.top() <= suf[ptr]) {
      printf("%c", st.top());
      st.pop();
    } else {
      while (ptr <= n && str[ptr] != suf[ptr]) {
        st.push(str[ptr++]);
      }
      st.push(str[ptr++]);
      printf("%c", st.top());
      st.pop();
    }
  }
  printf("\n");
  return 0;
}
