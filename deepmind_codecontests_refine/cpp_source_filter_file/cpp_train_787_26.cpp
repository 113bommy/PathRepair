#include <bits/stdc++.h>
using namespace std;
char ans[300001];
int main() {
  string S1, S2;
  cin >> S1 >> S2;
  sort(S1.begin(), S1.end());
  sort(S2.begin(), S2.end());
  int a1 = 0;
  int a2 = (S2.size() / 2);
  int b1 = ((S2.size() - 1) / 2);
  int b2 = S2.size() - 1;
  int x = S2.size() - 1;
  int s = 0;
  for (int i = 0; i < S1.size(); i++) {
    if (i % 2 == 0) {
      if (S1[a1] < S2[b2]) {
        ans[s] = S1[a1];
        s++;
        a1++;
      } else {
        ans[x] = S1[b1];
        b1--;
        x--;
      }
    } else {
      if (S2[b2] > S1[a1]) {
        ans[s] = S2[b2];
        b2--;
        s++;
      } else {
        ans[x] = S2[a2];
        a2++;
        x--;
      }
    }
  }
  cout << ans << endl;
}
