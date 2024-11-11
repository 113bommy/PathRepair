#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  while (n--) {
    int a;
    cin >> a;
    mp[a]++;
  }
  vector<int> v;
  for (auto i : mp) {
    if (i.second % 2 == 0)
      continue;
    else {
      v.push_back(i.first);
    }
  }
  int sum = 0;
  for (int i = 1; i < v.size(); i += 2) sum += abs(v[i] - v[i - 1]);
  printf("%d\n", sum);
}
