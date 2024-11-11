#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  if (((int)((a).size())) == ((int)((b).size()))) {
    sort(((a).begin()), ((a).end()));
    sort(((b).begin()), ((b).end()));
    if (a == b)
      cout << "array";
    else
      cout << "need tree";
  } else {
    if (((int)((b).size())) > ((int)((a).size()))) {
      cout << "need tree";
      return 0;
    }
    int cur = 0;
    for (int i = 0; i < ((int)((a).size())); ++i)
      if (a[i] == b[cur]) cur++;
    if (cur == ((int)((b).size())))
      cout << "automaton";
    else {
      cur = 0;
      for (int i = 0; i < ((int)((b).size())); ++i) {
        size_t found = a.find(b[i]);
        if (found != string::npos) {
          cur++;
          a.erase(a.begin() + i);
        }
      }
      if (cur == ((int)((b).size())))
        cout << "both";
      else
        cout << "need tree";
    }
  }
}
