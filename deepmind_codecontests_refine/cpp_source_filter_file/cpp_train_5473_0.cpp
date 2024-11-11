#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void trainGame() {
    int n, m, k;
    cin >> n >> m >> k;
    string to, line;
    cin >> to >> line;
    string minutes;
    cin >> minutes;
    bool head = false;
    string answer = "";
    if (line.compare("head") == 0) head = true;
    int s = m;
    int c = k;
    for (size_t i = 0; i < minutes.length(); i++) {
      if (minutes[i] == '1') {
        s = c;
        c = head ? c-- : c++;
      } else {
        if (c < s)
          s = s + 1 > n ? n : s + 1;
        else
          s = s - 1 < 1 ? 1 : s - 1;
        c = head ? c - 1 : c + 1;
        if (c == s) {
          cout << "Controller " << i + 1 << endl;
          return;
        }
      }
      if (c == n) head = true;
      if (c == 1) head = false;
    }
    cout << "Stowaway" << '\n';
    return;
  }
};
int main() {
  Solution obj;
  obj.trainGame();
  return 0;
}
