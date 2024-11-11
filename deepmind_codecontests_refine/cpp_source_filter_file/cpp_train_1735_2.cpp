#include <bits/stdc++.h>
using namespace std;
set<unsigned long long> s;
int main() {
  int n;
  cin >> n;
  vector<unsigned long long> v(n);
  unsigned long long b = 0;
  int maxi = -100;
  int mini = 1000000;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    s.insert(v[i]);
    int k = 0;
    unsigned long long tmp = v[i];
    while (tmp % 3 == 0) {
      tmp /= 3;
      k++;
    }
    int c = 0;
    while (tmp % 2 == 0) {
      tmp /= 2;
      c++;
    }
    if (k >= maxi && c < mini) {
      maxi = k;
      mini = c;
      b = v[i];
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << b << " ";
    if (b % 3 == 0 && s.find(b / 3) != s.end()) {
      b /= 3;
    } else {
      b *= 2;
    }
  }
}
