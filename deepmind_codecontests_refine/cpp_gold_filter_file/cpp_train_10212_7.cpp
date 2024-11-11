#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
long long greaterCounter(int m) {
  vector<int> s(2 * (n + 10), 0);
  int sum = n;
  long long result = 0;
  s[sum] = 1;
  long long add = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < m) {
      sum--;
      add -= s[sum];
    } else {
      add += s[sum];
      sum++;
    }
    result += add;
    s[sum]++;
  }
  return result;
}
int main() {
  int m;
  cin >> n >> m;
  a = vector<int>(n);
  for (int &ai : a) cin >> ai;
  cout << greaterCounter(m) - greaterCounter(m + 1) << endl;
}
