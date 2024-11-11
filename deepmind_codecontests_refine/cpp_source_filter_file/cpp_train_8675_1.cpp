#include <bits/stdc++.h>
using namespace std;
int N;
int H = 1, W = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  string A;
  for (int i = 1; i <= N; i++) {
    cin >> A;
    if (A.size() == 4)
      H++, W++;
    else if (A == "UL" || A == "DR")
      H++;
    else
      W++;
  }
  cout << W * H << "\n";
}
