#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int easy_or_hard = 0;
  for (int i = 0; i < n; i++) {
    int vote;
    cin >> vote;
    easy_or_hard = max(easy_or_hard, vote);
  }
  if (easy_or_hard == 1) {
    cout << "Hard" << '\n';
  } else {
    cout << "Easy" << '\n';
  }
  return 0;
}
