#include <bits/stdc++.h>
using namespace std;
string x;
string y;
long long n, m;
long long num[26][1000010];
int gcd(int a, int b) {
  int c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
int main() {
  cin >> n >> m;
  cin >> x;
  cin >> y;
  int lenx = x.length();
  int leny = y.length();
  int great = gcd(lenx, leny);
  long long commonLength = (long long)lenx * leny / great;
  for (int i = 0; i < lenx; i++) {
    int posAlpha = x[i] - 'a';
    int modd = i % great;
    num[x[i] - 'a'][i % great]++;
  }
  long long ans = 0;
  for (int i = 0; i < leny; i++) {
    int posAlpha = y[i] - 'a';
    int modd = i % great;
    long long currentNum = num[y[i] - 'a'][i % great];
    if (currentNum > 0) ans += currentNum;
  }
  ans = commonLength - ans;
  ans = (long long)n * lenx / commonLength * ans;
  cout << ans << endl;
  return 0;
}
