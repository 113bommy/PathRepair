#include <bits/stdc++.h>
using namespace std;
int compare(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int mini(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}
int maxi(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
struct box {
  int x;
  int y;
};
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
map<string, int> a;
map<string, int>::iterator it;
int main() {
  int n, m;
  string s;
  int b;
  double k;
  scanf("%d%d%lf", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    cin >> s >> b;
    if (b * k >= 100) {
      a[s] = b * (k + 0.000001);
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> s;
    b = a[s];
  }
  int sum = 0;
  for (it = a.begin(); it != a.end(); it++) {
    sum++;
  }
  cout << sum << endl;
  for (it = a.begin(); it != a.end(); it++) {
    cout << (*it).first << " " << (*it).second << endl;
  }
}
