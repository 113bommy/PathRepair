#include <bits/stdc++.h>
using namespace std;
int main() {
  char str1[1000], str2[1000];
  int n;
  cin >> n;
  cin >> str1;
  cin >> str2;
  int swaps = 0;
  int i = 0;
  while (str1[i] != '\0') {
    int rem1 = str1[i] - '0';
    int rem2 = str2[i] - '0';
    int maxi = max(rem1, rem2);
    int mini = min(rem1, rem2);
    if (maxi - mini < (10 + mini) - maxi) {
      swaps += maxi - mini;
    } else {
      swaps += (10 + mini) - maxi;
    }
    i++;
  }
  cout << swaps;
}
