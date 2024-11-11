#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  vector<int> v;
  int next = 1;
  int s = 0;
  while (s + next <= a + b) {
    s += next;
    v.push_back(next++);
  }
  int split = v.size();
  s = 0;
  for (int i = 0; i < v.size(); i++) {
    s += v[i];
    if (s >= a) {
      if (s > a) {
        split = i;
        swap(v[split], v[s - a - 1]);
      } else {
        split = i + 1;
      }
      break;
    }
  }
  cout << split << endl;
  for (int i = 0; i < split; i++) {
    cout << v[i] << (i + 1 == split ? '\n' : ' ');
  }
  cout << (v.size() - split) << endl;
  for (int i = split; i < v.size(); i++) {
    cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
  }
  return 0;
}
