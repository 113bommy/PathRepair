#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int Max[3];
  int Min[3];
  int brayce[3];
  int sum = 0;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    cin >> Min[i] >> Max[i];
    brayce[i] = Min[i];
    sum += Min[i];
  }
  int flag = 0;
  while (1) {
    if (sum == n || flag > 2) break;
    if (brayce[flag] == Max[flag]) {
      flag++;
      continue;
    }
    brayce[flag]++;
    sum++;
  }
  for (int i = 0; i < 3; i++) cout << brayce[i] << " ";
  cout << endl;
  return 0;
}
