#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];
  vector<int> ans(3);
  if (v[1] < v[2]) {
    if (v[0] < v[1]) {
      ans[0] = v[0];
    } else {
      ans[0] = v[1] - 1;
    }
  } else {
    v[1] = v[2] - 1;
    if (v[0] < v[1]) {
      ans[0] = v[0];
    } else {
      ans[0] = v[1] - 1;
    }
  }
  cout << v[0] * 3 + 3 << endl;
  return 0;
}
