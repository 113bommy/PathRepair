#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < (10); i++) {
    cout << i << "\n";
    fflush(stdout);
    string s;
    getline(cin, s);
    if (s == "great!" || s == "cool" || s == "don't think so" ||
        s == "not bad" || s == "don't touch me") {
      cout << "normal";
      fflush(stdout);
      return 0;
    }
    if (s == "DON'T EVEN" || s == "no way" || s == "NO" ||
        s == "are you serious?" || s == "terrible" || s == "worse" ||
        s == "go die in a hole") {
      cout << "grumpy";
      fflush(stdout);
      return 0;
    }
    s.clear();
  }
}
