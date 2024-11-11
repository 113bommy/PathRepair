#include <bits/stdc++.h>
using namespace std;
pair<int, int> v[100050];
pair<int, int> o[100050];
long long printDivisor(int n, int b, int a) {
  long long ans = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        if (v[i].first == 0 || v[i].second < a - b) {
          v[i].first = 1;
          v[i].second = a;
          ans++;
        } else {
          v[i].second = a;
        }
      } else {
        if (v[i].first == 0 || v[i].second < a - b) {
          v[i].first = 1;
          v[i].second = a;
          ans++;
        } else {
          v[i].second = a;
        }
        if (v[n / i].first == 0 || v[n / i].second < a - b) {
          v[n / i].first = 1;
          v[n / i].second = a;
          ans++;
        } else {
          v[n / i].second = a;
        }
      }
    }
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    cout << printDivisor(x, y, i) << "\n";
  }
  return 0;
}
