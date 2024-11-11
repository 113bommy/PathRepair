#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> num(n);
  set<int> all;
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
    all.insert(num[i]);
  }
  for (int i = num.size() - 1; i >= 0; --i) {
    if (all.size() > 1 && all.count(num[i]) != 0) all.erase(num[i]);
  }
  auto answer = all.begin();
  cout << *answer;
}
