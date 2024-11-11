#include <bits/stdc++.h>
using namespace std;
void pre() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  pre();
  int tests = 1;
  while (tests--) {
    string s;
    cin >> s;
    const set<char> vowelsEven = {'a', 'e', 'i', 'o', 'u',
                                  '0', '2', '4', '6', '8'};
    int cnt = 0;
    for (auto ch : s) {
      if (vowelsEven.find(ch) != vowelsEven.end()) cnt++;
    }
    cout << cnt << '\n';
  }
  return 0;
}
