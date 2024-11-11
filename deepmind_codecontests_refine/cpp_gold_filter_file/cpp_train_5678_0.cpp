#include <bits/stdc++.h>
using namespace std;
int solve(int i) {
  int ret = 0;
  while (i) {
    ret += (i / 5);
    i /= 5;
  }
  return ret;
}
vector<int> x;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 1000000; i++) {
    if (solve(i) == n) x.push_back(i);
  }
  cout << (int)x.size() << endl;
  for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
  cout << endl;
}
