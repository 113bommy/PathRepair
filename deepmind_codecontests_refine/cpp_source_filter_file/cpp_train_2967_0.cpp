#include <bits/stdc++.h>
using namespace std;
char BUFFER[100000 + 5];
bool readn(int &n) { return scanf("%d", &n) == 1; }
bool readl(long long &n) { return scanf("%I64d", &n) == 1; }
bool readd(double &n) { return scanf("%lf", &n) == 1; }
bool reads(string &s) {
  s = "";
  int n = scanf("%s", BUFFER);
  if (n == 1) s = BUFFER;
  return n == 1;
}
bool readln(string &s) {
  char *valid = gets(BUFFER);
  if (valid) s = BUFFER;
  return ((bool)valid);
}
void Print(long long &n, bool printNewLine = true) {
  printNewLine ? printf("%I64d\n", n) : printf("%I64d", n);
}
const int maxn = 1e6 + 10;
int prime[maxn], palindrome[maxn];
void MakePalindrome(int n, int &p1, int &p2) {
  vector<int> v(0);
  p1 = p2 = n;
  int i;
  while (n > 0) {
    v.push_back(n % 10);
    n /= 10;
  }
  p2 = p2 * 10 + v[0];
  for (i = 1; i < ((int)v.size()); ++i) {
    p1 = p1 * 10 + v[i];
    p2 = p2 * 10 + v[i];
  }
}
void init() {
  int i, j, p1, p2;
  for (i = 0; i < maxn; ++i) {
    prime[i] = 1;
    palindrome[i] = 0;
  }
  prime[0] = prime[1] = 0;
  palindrome[0] = 0;
  for (i = 2; i * i <= maxn; i++)
    if (prime[i]) {
      for (j = i + i; j <= maxn; j += i) prime[j] = 0;
    }
  for (i = 1; i <= maxn; i++) {
    MakePalindrome(i, p1, p2);
    if (p1 < maxn)
      palindrome[p1] = 1;
    else
      break;
    if (p2 < maxn) palindrome[p2] = 1;
  }
  for (i = 1; i < maxn; ++i) {
    prime[i] += prime[i - 1];
    palindrome[i] += palindrome[i - 1];
  }
}
int main() {
  init();
  int i, n = 0, p, q;
  cin >> p >> q;
  for (i = 1; i < maxn; ++i) {
    if (prime[i] * q <= palindrome[i] * p) n = i;
  }
  if (n)
    cout << n << endl;
  else
    cout << "Palindromic tree is better than splay tree" << endl;
  return 0;
}
