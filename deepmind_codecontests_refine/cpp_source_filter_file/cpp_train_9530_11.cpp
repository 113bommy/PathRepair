#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string name;
  int oldRating, newRating;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> name >> oldRating >> newRating;
    if (oldRating >= 2500 && oldRating < newRating) {
      ans = 1;
    }
  }
  if (ans)
    cout << "YES";
  else
    cout << "NO";
}
