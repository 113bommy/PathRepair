#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  vector<int> a;
  int tmp;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  vector<int> t(a);
  a.clear();
  a.push_back(t[0]);
  for (int i = 1; i != t.size() - 1; ++i) {
    if (t[i] != t[i - 1]) {
      a.push_back(t[i]);
    }
  }
  if (a.back() < a.front() * pow(2, a.size() - 1)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
