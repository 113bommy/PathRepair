#include <bits/stdc++.h>
using namespace std;
int main() {
  int Anton = 0, Danik = 0, n;
  cin >> n;
  string win;
  cin >> win;
  for (int i = 0; i < n; i++) {
    if (win[i] == 'A')
      Anton++;
    else
      Danik++;
  }
  if (Anton > Danik)
    cout << "Anton";
  else if (Danik > Anton)
    cout << "Danik";
  else
    cout << "Friendship";
}
