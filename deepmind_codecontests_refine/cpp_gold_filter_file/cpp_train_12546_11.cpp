#include <bits/stdc++.h>
using namespace std;
bool comp(int x, int y) { return x > y; }
int main() {
  int a;
  cin >> a;
  vector<int> v;
  vector<int> v1;
  for (int i = 0; i < a; i++) {
    int x;
    cin >> x;
    if (x % 2)
      v.push_back(x);
    else
      v1.push_back(x);
  }
  unsigned long long int sum = 0;
  sort(v.begin(), v.end(), comp);
  sort(v1.begin(), v1.end());
  if (v.size() % 2 && v.size() > 1) {
    for (int i = 0; i < v.size() - 1; i++) {
      sum += v[i];
    }
  } else if (v.size() > 1) {
    for (int i = 0; i < v.size(); i++) {
      sum += v[i];
    }
  }
  for (int i = 0; i < v1.size(); i++) sum += v1[i];
  cout << sum << endl;
  return 0;
}
