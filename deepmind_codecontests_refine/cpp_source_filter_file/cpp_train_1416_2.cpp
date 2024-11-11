#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, p = "";
  cin >> s;
  int i, h, m;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == ':') {
      h = stoi(p);
      p = "";
    } else
      p += s[i];
  }
  m = stoi(p);
  p = "";
  double hour = m * (0.5);
  if (h == 12)
    ;
  else
    hour += (30 * h);
  double mint = m * 6;
  if (h - int(h) != 0) {
    cout << fixed << setprecision(1) << hour << " ";
    cout << mint << endl;
  } else
    cout << hour << " " << mint << endl;
}
