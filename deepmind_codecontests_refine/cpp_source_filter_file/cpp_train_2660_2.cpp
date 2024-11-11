#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v(4);
  for (int i = 0; i < 4; i++) cin >> v[i];
  sort(v.rbegin(), v.rend());
  if (v[0] < v[3] + v[2])
    cout << "TRIANGLE";
  else if (v[1] < v[3] + v[2])
    cout << "TRIANGLE";
  else if (v[1] == v[3] + v[2])
    cout << "SEGMENT";
  else if (v[0] == v[3] + v[2])
    cout << "SEGMENT";
  else if (v[0] == v[3] + v[1])
    cout << "SEGMENT";
  else if (v[0] == v[1] + v[2])
    cout << "SEGMENT";
  else
    cout << "IMPOSSIBLE";
  return 0;
}
