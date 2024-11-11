#include <bits/stdc++.h>
using namespace std;
int main() {
  int ea = 0;
  int eb = 0;
  int aa = 0;
  string tmp;
  cin >> tmp;
  for (int i = 0; i < tmp.size(); i++) {
    if (tmp[i] == 'a') {
      aa++;
      ea = max(ea + 1, eb + 1);
    }
    if (tmp[i] == 'b') {
      eb = max(aa + 1, eb + 1);
    }
  }
  cout << max(ea, eb) << endl;
  return 0;
}
