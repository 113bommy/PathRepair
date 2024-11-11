#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a;
  while (n--) {
    a.push_back(1);
    while (a.size() > 1 && a[a.size() - 1] == a[a.size() - 2]) {
      int val = a[a.size() - 1];
      a.pop_back();
      a.pop_back();
      a.push_back(val + 1);
    }
  }
  for (int i = 0; i < a.size(); ++i) {
    printf("%d ", a[i]);
  }
  return 0;
}
