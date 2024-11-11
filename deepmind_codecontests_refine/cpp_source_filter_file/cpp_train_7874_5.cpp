#include <bits/stdc++.h>
const long double eps = 0.00000001;
const long long MOD = 1e9 + 7;
using namespace std;
bool b;
set<string> s1 = {"cool", "great!", "don't think so", "don't touch me!",
                  "not bad"};
set<string> s2 = {"worse",  "terrible",        "don't even", "are you serious?",
                  "no way", "go die in a hole"};
int main() {
  ios_base::sync_with_stdio(false);
  int i, j, n;
  for (i = 0; i < 10; ++i) {
    fflush(stdout);
    fflush(stdin);
    cout << i << endl;
    fflush(stdout);
    fflush(stdin);
    string ss = "";
    getline(cin, ss);
    fflush(stdin);
    fflush(stdout);
    if (s2.count(ss))
      return cout << "grumpy\n", 0;
    else if (s1.count(ss))
      return cout << "normal\n", 0;
  }
  fflush(stdout);
  fflush(stdin);
  return cout << "grumpy\n", 0;
}
