#include <bits/stdc++.h>
using namespace std;
set<int> todos;
void calc(int lim, int a, int b, bool prend) {
  if (2000000000 < 1ll * pow(2, a) * pow(3, b)) {
    return;
  }
  todos.insert(pow(2, a) * pow(3, b));
  if (prend) {
    calc(lim, a, b + 1, true);
  } else {
    calc(lim, a + 1, b, false);
    calc(lim, a, b + 1, true);
  }
}
int main() {
  int a, b;
  cin >> a >> b;
  vector<long long> v2, v3;
  int x = 1;
  for (int i = 0; i <= 30; i++) {
    v2.push_back(x);
    x *= 2;
  }
  x = 1;
  for (int i = 0; i <= 19; i++) {
    v3.push_back(x);
    x *= 3;
  }
  for (int i = 0; i < v2.size(); i++) {
    for (int j = 0; j < v3.size(); j++) {
      if (v2[i] * v3[j] <= 2e9) {
        todos.insert(v2[i] * v3[j]);
      }
    }
  }
  int c = 0;
  auto it = lower_bound(todos.begin(), todos.end(), a);
  for (; *it < b && it != todos.end(); it++) {
    c++;
  }
  cout << c;
}
