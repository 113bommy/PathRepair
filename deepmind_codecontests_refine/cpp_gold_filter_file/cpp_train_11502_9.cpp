#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n';
  err(++it, args...);
}
template <typename T>
T readnum() {
  char c;
  do {
    c = getchar();
  } while (!(c >= '0' and c <= '9'));
  T x = 0;
  while ((c >= '0' and c <= '9')) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
int func(int* p, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int mi = p[i];
      for (int k = i; k <= j; k++) {
        mi = min(mi, p[k]);
      }
      sum += mi;
    }
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int p[n + 10];
  for (int i = 0; i < n; i++) {
    p[i] = i + 1;
  }
  int hatar = n;
  for (int i = 2; i < n; i++) {
    hatar *= i;
  }
  int f[hatar];
  for (int i = 0; i < hatar; i++) {
    f[i] = 0;
  }
  for (int i = 0; i < hatar; i++) {
    f[i] = func(p, n);
    next_permutation(p, p + n);
  }
  int maxval = f[0];
  for (int i = 0; i < hatar; i++) {
    maxval = max(maxval, f[i]);
  }
  int hely = 0;
  int k;
  for (k = 0; k < hatar; k++) {
    if (f[k] == maxval) {
      hely++;
    }
    if (hely == m) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    p[i] = i + 1;
  }
  for (int i = 0; i < k; i++) {
    next_permutation(p, p + n);
  }
  for (int i = 0; i < n; i++) {
    cout << p[i] << " \n"[n - 1 == i];
  }
}
