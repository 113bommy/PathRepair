#include <bits/stdc++.h>
using namespace std;
int main() {
  int problems;
  cin >> problems;
  int res = 0;
  string infos[problems];
  for (int i = 0; i < problems; i++) {
    if (cin.peek() == '\n') cin.ignore();
    string word;
    getline(cin, word);
    infos[i] = word;
  }
  for (int i = 0; i < problems; i++) {
    int h = 0;
    for (int k = 0; k < 5; k++) {
      if (infos[i][k] == '1') h++;
    }
    if (h > 2) res++;
  }
  cout << res;
}
