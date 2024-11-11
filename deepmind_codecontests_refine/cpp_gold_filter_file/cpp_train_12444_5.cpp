#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main(void) {
  string a;
  getline(cin, a);
  int pl = 0, m = 0;
  int n = 0;
  int fl = 0;
  for (auto i : a) {
    if (fl == 3 && i >= '0' && i <= '9') {
      n += i - '0';
      n *= 10;
    } else if (i == '+')
      pl++;
    else if (i == '-')
      m++;
    else if (i == '=')
      fl = 3;
  }
  n /= 10;
  pl += 1;
  fl = 1;
  int done = 0;
  int rem = pl - 1;
  if ((pl * n) < n + m || pl > n + (n * m)) {
    cout << "Impossible" << endl;
  } else {
    cout << "Possible" << endl;
    int x = 0;
    for (x = 1; x <= n; x++) {
      if (pl <= n + (x * m)) break;
    }
    for (auto i : a) {
      if (i == '+')
        fl = 1;
      else if (i == '-')
        fl = 2;
      if (i == '?') {
        if (fl == 1) {
          if (n + done + (rem * 1) <= n + (x * m)) {
            done += n;
            rem--;
            cout << n;
          } else {
            if (rem + 1 + done == n + (x * m)) {
              done++;
              rem--;
              cout << 1;
            } else {
              cout << (n + (x * m)) - rem - done;
              done += (n + (x * m)) - rem - done;
              rem--;
            }
          }
        } else if (fl == 2) {
          cout << x;
        }
      } else
        cout << i;
    }
    cout << endl;
  }
  return (0);
}
