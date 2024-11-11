#include <bits/stdc++.h>
using namespace std;
int main() {
  int last = 0;
  long long n = 0, a = 0, s1 = 0, s2 = 0;
  cin >> n;
  vector<long long> p1, p2;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a > 0) {
      p1.push_back(a);
      last = 0;
    } else {
      a *= -1;
      p2.push_back(a);
      last = 1;
    }
  }
  for (int i = 0; i < p1.size(); i++) {
    s1 += p1[i];
  }
  for (int i = 0; i < p2.size(); i++) {
    s2 += p2[i];
  }
  if (s1 > s2) {
    cout << "first";
  } else if (s2 > s1) {
    cout << "second";
  } else {
    for (int i = 0; i < p1.size(); i++) {
      if (p1[i] > p2[i]) {
        cout << "first";
        return 0;
      } else if (p2[i] > p1[i]) {
        cout << "second";
        return 0;
      }
    }
    if (last == 0) {
      cout << "first";
    } else {
      cout << "second";
    }
  }
  return 0;
}
