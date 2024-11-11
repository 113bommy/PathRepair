#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  queue<int> x;
  int g = n;
  int b = 1;
  int k = 1;
  while (n--) {
    if (b + k > g)
      b = (b + k) % g;
    else
      b = b + k;
    x.push(b);
    k++;
  }
  int c = x.size();
  for (int i = 0; i < c - 1; i++) {
    int t = x.front();
    x.pop();
    cout << t;
    if (i != c - 1) cout << " ";
  }
  return 0;
}
