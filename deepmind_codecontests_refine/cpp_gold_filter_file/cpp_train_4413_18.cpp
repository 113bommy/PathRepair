#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k = n;
  vector<int> d;
  d.push_back(0);
  while (n > 0) {
    int temp;
    cin >> temp;
    d.push_back(temp);
    n--;
  }
  int s, t;
  cin >> s;
  cin >> t;
  if (t < s) swap(s, t);
  int a = 0;
  for (int i = s; i <= t - 1; i++) {
    a += d[i];
  }
  int b = 0;
  for (int i = t; i <= k; i++) {
    b += d[i];
  }
  for (int i = 1; i < s; i++) {
    b += d[i];
  }
  if (a < b)
    cout << a;
  else
    cout << b;
}
