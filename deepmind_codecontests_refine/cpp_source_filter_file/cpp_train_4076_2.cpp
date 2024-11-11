#include <bits/stdc++.h>
using namespace std;
int interact(vector<int> v) {
  cout << "next";
  for (int i : v) {
    cout << " " << i;
  }
  cout << ("") << endl;
  ;
  cout.flush();
  int k;
  cin >> k;
  ;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    ;
  }
  return k;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  do {
    interact({0});
  } while (interact({0, 1}) == 2);
  while (interact({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) == 2)
    ;
  cout << ("done") << endl;
  ;
}
