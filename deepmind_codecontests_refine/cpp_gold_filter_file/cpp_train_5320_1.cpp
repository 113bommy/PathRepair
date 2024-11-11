#include <bits/stdc++.h>
using namespace std;
int mas[15000001];
bool vis[15000001];
long long l[500000];
long long resheto() {
  long long ans = 0;
  for (int i = 2; i < 15000001; i++) {
    if (vis[i] == false) {
      long long tmp = 0;
      for (int j = i; j < 15000001; j += i) {
        tmp += mas[j];
        vis[j] = true;
      }
      ans = max(ans, tmp);
    }
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n;
  cin >> n;
  long long gcdd;
  cin >> l[0];
  gcdd = l[0];
  for (int i = 1; i < n; i++) {
    cin >> l[i];
    gcdd = gcd(gcdd, l[i]);
  }
  for (int i = 0; i < n; i++) {
    mas[l[i] / gcdd] += 1;
  }
  long long f = resheto();
  if (f == 0) {
    cout << -1 << endl;
  } else {
    cout << n - f << endl;
  }
  return 0;
}
