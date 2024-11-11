#include <bits/stdc++.h>
using namespace std;
long long _pow(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long t = _pow(a, b / 2, m);
  t = (t * t) % m;
  if (b & 1)
    return (t * a) % m;
  else
    return t;
}
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<string> v;
  int cnt = 0;
  bool zero = false;
  string ex = "";
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    v.push_back(x);
    bool f = true;
    if (x[0] == '0' and x.size() == 1)
      zero = true;
    else if (x[0] == '1') {
      int cn = 0;
      int j;
      for (j = 1; j < x.size(); j++)
        if (x[j] != '0') {
          ex = x;
          break;
        } else
          cn++;
      if (j == x.size()) cnt += cn;
    } else
      ex = x;
  }
  if (zero)
    cout << 0 << endl;
  else {
    cout << ex;
    for (int i = 0; i < cnt; i++) cout << 0;
    cout << endl;
  }
  return 0;
}
