#include <bits/stdc++.h>
using namespace std;
void Code_Forces() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  Code_Forces();
  int n, k;
  cin >> n >> k;
  char password = 'a';
  for (int i = 0; i < n; i++, password++) {
    if (i == k) password = 'a';
    cout << password;
  }
  return 0;
}
