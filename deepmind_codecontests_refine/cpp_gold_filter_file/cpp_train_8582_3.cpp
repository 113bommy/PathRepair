#include <bits/stdc++.h>
using namespace std;
int arr[6];
int main() {
  int i, j, cases;
  long long int n;
  string str1;
  char poke[][11] = {"jolteon", "flareon", "umbreon",
                     "leafeon", "glaceon", "sylveon"};
  cin >> n;
  cin >> str1;
  if (n == 8) {
    cout << "vaporeon";
    return 0;
  }
  if (n == 6) {
    cout << "espeon";
    return 0;
  }
  for (i = 0; i < 7; i++) {
    if (str1[i] == '.') continue;
    if (str1[i] == poke[0][i]) arr[0]++;
    if (str1[i] == poke[1][i]) arr[1]++;
    if (str1[i] == poke[2][i]) arr[2]++;
    if (str1[i] == poke[3][i]) arr[3]++;
    if (str1[i] == poke[4][i]) arr[4]++;
    if (str1[i] == poke[5][i]) arr[5]++;
  }
  int maxn = -1;
  int maxi;
  for (i = 0; i < 6; i++) {
    if (arr[i] > maxn) {
      maxn = arr[i];
      maxi = i;
    }
  }
  cout << poke[maxi];
  printf("\n");
  return 0;
}
