#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  char oper;
  cin >> b;
  while (cin >> oper >> a) {
    if (oper == '+')
      b += a;
    else
      b -= a;
  }
  string ans = to_string(b);
  for (int i = 0; i < ans.size() - 1; i++) cout << string(ans[i], '+') << ".>";
  cout << string(ans[ans.size() - 1], '+') << "." << endl;
}
