#include <bits/stdc++.h>
using namespace std;
namespace task {
string s, t;
int k;
int main() {
  cin >> s >> t;
  for (k = 0; k < min(s.size(), t.size()) &&
              s[s.size() - 1 - k] == t[t.size() - 1 - k];
       ++k)
    ;
  cout << s.size() + t.size() - k << '\n';
  return 0;
}
}  // namespace task
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(11);
  cout.setf(ios::fixed);
  return task::main();
}
