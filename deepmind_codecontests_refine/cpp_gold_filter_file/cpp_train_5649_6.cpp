#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b);
long long int gcd(long long int a, long long int b);
int prime(int n);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    long long int n = a.size();
    long long int b[n];
    long long int ans = 1, mi = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (a[i] == '+')
        ans++;
      else
        ans--;
      mi = min(mi, ans);
      b[i] = ans;
    }
    long long int fi = 0;
    if (mi > 0)
      cout << n << endl;
    else {
      mi = abs(mi);
      ans = 0;
      for (int i = 0; i < n; i++) {
        if ((-1) * b[i] == ans) {
          fi += (i + 1);
          ans++;
        }
      }
      fi += n;
      cout << fi << endl;
    }
  }
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int prime(int n) {
  int flag = 1;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      flag = 0;
      break;
    }
  }
  return flag;
}
