#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  sort(S.begin(), S.end());
  cout << ((S == "ABC") ? "Yes" : "No") << endl;
}
