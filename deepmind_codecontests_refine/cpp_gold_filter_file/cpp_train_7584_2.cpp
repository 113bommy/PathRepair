#include <bits/stdc++.h>
using namespace std;

string c[3];
int now[3] = {0}, t = 0;

int main() {
  for(int i = 0; i < 3; ++i) cin >> c[i];
  while(1) {
    if(now[t] == c[t].size()) break;
    ++now[t];
    t = c[t][now[t] - 1] - 'a';
  }

  cout << (char)(t + 'A') << endl;
  return 0;
}