#include <bits/stdc++.h>
using namespace std;
vector<int> v;
map<int, int> m;
void primes(int n) {
  bool a[n + 1];
  for (int i = 1; i <= n; i++) {
    a[i] = false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (a[i] == false) {
      for (int j = i * i; j <= n; j += i) {
        a[j] = true;
        m[j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == true) {
      v.push_back(i);
    }
  }
}
int main() {
  int n;
  cin >> n;
  int c = 0;
  primes(n);
  for (int i = 0; i < v.size(); i++) {
    if (m[v[i]] == 2) {
      c++;
    }
  }
  cout << c;
}
