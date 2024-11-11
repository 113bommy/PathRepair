#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    string input;
    cin >> input;
    int R = 0, S = 0, P = 0;
    for (int i = 0; i < input.size(); ++i) {
      if (input[i] == 'R') R++;
      if (input[i] == 'S') S++;
      if (input[i] == 'P') P++;
    }
    if (R >= S and R >= P) {
      for (int i = 0; i < input.size(); ++i) cout << 'P';
    } else if (S >= R and S >= P) {
      for (int i = 0; i < input.size(); ++i) cout << 'R';
    } else {
      for (int i = 0; i < input.size(); ++i) cout << 'P';
    }
    cout << '\n';
  }
}
