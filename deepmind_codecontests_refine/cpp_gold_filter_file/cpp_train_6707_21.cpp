#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  string line;
  int c[4] = {0};
  cin >> line;
  for (size_t i = 0; i < line.size(); i++) {
    if (line[i] == 'n') c[0]++;
    if (line[i] == 'i') c[1]++;
    if (line[i] == 't') c[2]++;
    if (line[i] == 'e') c[3]++;
  }
  c[0]--;
  c[0] = c[0] / 2;
  c[3] = c[3] / 3;
  int min = c[0];
  if (c[2] < min) min = c[2];
  if (c[1] < min) min = c[1];
  if (c[3] < min) min = c[3];
  cout << min << endl;
  return 0;
}
