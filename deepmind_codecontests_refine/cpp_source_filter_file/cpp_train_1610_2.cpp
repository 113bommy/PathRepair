#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool np[100001] = {true, true};
  for (int i = 2; i < 1000; i++)
    if (!np[i])
      for (int j = 2; i * j < 100000; j++) np[i * j] = true;
  vector<int> two, v;
  bool used[100001] = {0};
  for (int i = n; i > 2; i--)
    if (!np[i]) {
      vector<int> tv;
      for (int j = 1; i * j <= n; j++)
        if (!used[i * j]) {
          used[i * j] = true;
          tv.push_back(i * j);
        }
      if (tv.size() <= 1) continue;
      int start;
      if (tv.size() % 2) {
        two.push_back(tv[1]);
        tv[1] = tv[0];
        start = 1;
      } else
        start = 0;
      for (int j = start; j < tv.size(); j++) v.push_back(tv[j]);
    }
  for (int i = 1; 2 * i <= n; i++)
    if (!used[2 * i]) two.push_back(2 * i);
  v.insert(v.end(), two.begin(), two.end());
  cout << v.size() / 2 << endl;
  for (int i = 0; i < v.size() / 2; i++)
    cout << v[2 * i] << ' ' << v[2 * i + 1] << endl;
  return 0;
}
