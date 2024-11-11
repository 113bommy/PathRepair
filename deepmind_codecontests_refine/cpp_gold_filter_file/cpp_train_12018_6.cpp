#include <bits/stdc++.h>
using namespace std;
template <typename T>
string NumberToString(T Number) {
  ostringstream ss;
  ss << Number;
  return ss.str();
}
int main() {
  int count;
  cin >> count;
  int sol[100001];
  for (int i = 0; i < 100001; i++) sol[i] = -1;
  bool flag = true;
  for (int i = 0; i < count; i++) {
    int x, k;
    cin >> x >> k;
    if (sol[k] == x - 1 || sol[k] == x)
      sol[k] = x;
    else if (!(x < sol[k]))
      flag = false;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
