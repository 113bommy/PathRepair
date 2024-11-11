#include <bits/stdc++.h>
using namespace std;
int getplaces(string queu, int arr1[26], int (&arr)[100]) {
  int itr = 0, sizze = 0;
  sizze = queu.length();
  for (int i = 0; i < sizze; i++) {
    for (int x = 0; x < 26; x++) {
      if (int(queu[i]) == arr1[x]) {
        arr[itr] = x;
        itr++;
      }
    }
  }
  return itr;
}
int main() {
  int Ascii[28] = {111, 112, 113, 114, 115, 116, 117, 118, 119,
                   120, 121, 122, 97,  98,  99,  100, 101, 102,
                   103, 104, 105, 106, 107, 108, 109, 110},
      arr[100], sizze = 0, Ans = 0, p = 0, asciies = 0;
  string exhibitNmae;
  cin >> exhibitNmae;
  sizze = exhibitNmae.length();
  p = getplaces(exhibitNmae, Ascii, arr);
  for (int i = 0; i < p - 1; i++) {
    if (int(exhibitNmae[i]) > int(exhibitNmae[i + 1]))
      asciies = int(exhibitNmae[i]) - int(exhibitNmae[i + 1]);
    if (int(exhibitNmae[i]) <= int(exhibitNmae[i + 1]))
      asciies = int(exhibitNmae[i + 1]) - int(exhibitNmae[i]);
    if (arr[i] > arr[i + 1]) {
      if ((arr[i] - arr[i + 1]) < asciies)
        Ans = Ans + (arr[i] - arr[i + 1]);
      else
        Ans = Ans + asciies;
    }
    if (arr[i] < arr[i + 1]) {
      if ((arr[i + 1] - arr[i]) < asciies)
        Ans = Ans + (arr[i + 1] - arr[i]);
      else
        Ans = Ans + asciies;
    }
  }
  if (arr[0] > 12)
    Ans = Ans + (arr[0] - 12);
  else
    Ans = Ans + (12 - arr[0]);
  cout << Ans;
  return 0;
}
