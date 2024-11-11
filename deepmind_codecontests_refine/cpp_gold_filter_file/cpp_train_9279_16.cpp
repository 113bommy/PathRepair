#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
int main() {
  long long n, x, y;
  vector<long long> ch;
  cin >> n >> x >> y;
  ch.resize(n);
  if (y < n) {
    cout << "-1" << endl;
  } else {
    ch.assign(n, 1);
    ch[n - 1] = y - n + 1;
    if ((n - 1 + ch[n - 1] <= y) && (n - 1 + ch[n - 1] * ch[n - 1] >= x)) {
      for (int i = 0; i < ch.size(); i++) {
        cout << ch[i] << endl;
      }
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
