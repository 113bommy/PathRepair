#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  float s = 0;
  float pi;
  cin >> n;
  vector<float> p;
  for (int i = 0; i < n; i++) {
    cin >> pi;
    p.push_back(pi);
  }
  for (int i = 0; i < n; i++) {
    s = s + float(p[i] / 100);
  }
  cout << (float(s) / float(n)) * 100;
  return 0;
}
