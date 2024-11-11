#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 0; i != n; ++i) cin >> vec[i];
  vector<int> res;
  for (int i = 1; i != vec.size(); ++i)
    if (vec[i - 1] > vec[i]) res.push_back(vec[i - 1]);
  cout << res.size() << endl;
  bool isFirst = true;
  for (int i = 0; i != res.size(); ++i) {
    if (isFirst) {
      cout << res[i];
      isFirst = false;
    } else {
      cout << " " << res[i];
    }
  }
  cout << endl;
  return 0;
}
