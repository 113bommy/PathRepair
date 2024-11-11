#include <bits/stdc++.h>
using namespace std;
vector<long long int> a1, a2, remain;
long long int sum = 0;
int main() {
  long long int a, b, c, m;
  long long int x;
  long long int total = 0;
  cin >> a >> b >> c >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x;
    string s;
    cin >> s;
    if (s == "USB") {
      a1.push_back(x);
    } else {
      a2.push_back(x);
    }
  }
  sort(a1.begin(), a1.end());
  sort(a2.begin(), a2.end());
  int a1start = 0, a2start = 0;
  if (a1.size() >= a) {
    for (int i = 0; i < a; ++i) {
      sum += a1[i];
    }
    total = a;
    a1start = a;
  } else {
    total = a1.size();
    for (int i = 0; i < a1.size(); ++i) {
      sum += a1[i];
    }
    a1start = a1.size();
  }
  if (a2.size() >= b) {
    for (int i = 0; i < b; ++i) {
      sum += a2[i];
    }
    total += b;
    a2start = b;
  } else {
    total += a2.size();
    for (int i = 0; i < a2.size(); ++i) {
      sum += a1[i];
    }
    a2start = a2.size();
  }
  for (int i = a1start; i < a1.size(); ++i) {
    remain.push_back(a1[i]);
  }
  for (int i = a2start; i < a2.size(); ++i) {
    remain.push_back(a2[i]);
  }
  sort(remain.begin(), remain.end());
  for (int i = 0; i < remain.size(); ++i) {
    if (c > 0) {
      c -= 1;
      total += 1;
      sum += remain[i];
    }
  }
  cout << total << " " << sum;
}
