#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == 1 || b == 1) return 1;
  if (a == b) return a;
  if (a > b)
    return gcd(b, a % b);
  else
    return gcd(a, b % a);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<string> s;
  string temp;
  int a[n];
  int mx = 1, c = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    s.push_back(temp);
    c = 0;
    a[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (s[j] == temp) {
        a[i] += a[j];
        if (mx < a[i]) mx = a[i];
        break;
      }
    }
  }
  printf("%d\n", mx);
  return 0;
}
