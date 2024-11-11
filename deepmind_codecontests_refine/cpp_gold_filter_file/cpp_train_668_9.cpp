#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string S;
  cin >> S;
  long long odd = 0, even = 0, aodd = 0, aeven = 0, bodd = 0, beven = 0;
  for (int i = 0; i < S.length(); ++i)
    if (i & 1)
      if (S[i] == 'a') {
        aodd++;
        odd += aodd;
        even += aeven;
      } else {
        bodd++;
        odd += bodd;
        even += beven;
      }
    else if (S[i] == 'a') {
      aeven++;
      odd += aeven;
      even += aodd;
    } else {
      beven++;
      odd += beven;
      even += bodd;
    }
  cout << even << ' ' << odd << '\n';
  return 0;
}
