#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main() {
  int N;
  cin >> N;
  int minim = -2000000000;
  int maxim = 2000000000;
  for (int i = 0; i < N; i++) {
    string s;
    int lim;
    string ans;
    cin >> s >> lim >> ans;
    if (ans == "Y") {
      if (s == ">")
        minim = max(minim, lim + 1);
      else if (s == ">=")
        minim = max(minim, lim);
      else if (s == "<")
        maxim = min(maxim, lim - 1);
      else if (s == "<=")
        maxim = min(maxim, lim);
    } else {
      if (s == "<=")
        minim = max(minim, lim + 1);
      else if (s == "<")
        minim = max(minim, lim);
      else if (s == ">=")
        maxim = min(maxim, lim - 1);
      else if (s == ">")
        maxim = min(maxim, lim);
    }
  }
  if (minim <= maxim)
    cout << minim << endl;
  else
    cout << "impossible\n";
}
