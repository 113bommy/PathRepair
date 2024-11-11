#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
vector<long long int> initializeDiffArray(vector<long long int>& A);
void update(vector<long long int>& D, long long int l, long long int r,
            long long int x);
void getArray(vector<long long int>& A, vector<long long int>& D);
long long int min(long long int a, long long int b);
long long int max(long long int a, long long int b);
long long int gcd(long long int a, long long int b);
void swap(long long int* a, long long int* b);
long long int lcm(long long int a, long long int b);
long long int modpower(long long int x, long long int y, long long int p);
long long int power(long long int x, long long int y);
long long int modulo(long long int value, long long int m);
long long int myXOR(long long int x, long long int y);
long long int diff(long long int a, long long int b);
long long int isconso(char c) {
  string s = "aeiou";
  long long int flag = 0;
  for (long long int i = 0; i <= s.length() - 1; ++i)
    if (s[i] == c) return 0;
  return 1;
}
int main() {
  long long int rep = 1;
  while (rep--) {
    string s;
    cin >> s;
    long long int n = s.length();
    long long int i = 2;
    vector<long long int> ans;
    while (i < n) {
      if (isconso(s[i]) && isconso(s[i - 1]) && isconso(s[i - 2])) {
        if (s[i - 2] == s[i - 1 && s[i - 1] == s[i]])
          i++;
        else {
          ans.push_back(i);
          i += 2;
        }
      } else
        i++;
    }
    for (long long int i = 0; i <= n - 1; ++i) {
      if (ans.size())
        if (ans[0] == i) {
          cout << " ";
          ans.erase(ans.begin());
        }
      cout << s[i];
    }
  }
}
long long int myXOR(long long int x, long long int y) {
  return (x | y) & (~x | ~y);
}
long long int min(long long int a, long long int b) {
  if (a > b) return b;
  return a;
}
long long int max(long long int a, long long int b) {
  if (a < b) return b;
  return a;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int diff(long long int a, long long int b) {
  if (a > b) return a - b;
  return b - a;
}
void swap(long long int* a, long long int* b) {
  long long int t = *a;
  *a = *b;
  *b = t;
}
long long int lcm(long long int a, long long int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return (a * b) / gcd(a, b);
}
long long int modpower(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long int modulo(long long int value, long long int m) {
  long long int mod = value % m;
  if (value < 0) {
    mod += m;
  }
  return mod;
}
vector<long long int> initializeDiffArray(vector<long long int>& A) {
  long long int n = A.size();
  vector<long long int> D(n + 1);
  D[0] = A[0], D[n] = 0;
  for (long long int i = 1; i < n; i++) D[i] = A[i] - A[i - 1];
  return D;
}
void update(vector<long long int>& D, long long int l, long long int r,
            long long int x) {
  D[l] += x;
  D[r + 1] -= x;
}
void getArray(vector<long long int>& A, vector<long long int>& D) {
  for (long long int i = 0; i < A.size(); i++) {
    if (i == 0)
      A[i] = D[i];
    else
      A[i] = D[i] + A[i - 1];
  }
}
