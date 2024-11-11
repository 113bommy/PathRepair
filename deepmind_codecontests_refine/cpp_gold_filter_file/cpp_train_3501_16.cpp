#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int begin;
  int end;
  char x;
  char y;
} oper;
int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  string input;
  cin >> input;
  oper op[m];
  for (int i = 0; i < m; ++i) {
    cin >> op[i].begin >> op[i].end >> op[i].x >> op[i].y;
  }
  for (int i = 0; i < m; ++i) {
    char xx = op[i].x;
    char yy = op[i].y;
    for (int k = op[i].begin - 1; k < op[i].end; ++k) {
      if (input[k] == xx) {
        input[k] = yy;
      }
    }
  }
  cout << input << endl;
  return 0;
}
