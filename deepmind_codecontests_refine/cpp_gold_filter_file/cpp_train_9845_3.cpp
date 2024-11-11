#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char ch[n];
  int c = 0, d = 0;
  for (int i = 0; i < n; i++) {
    cin >> ch[i];
    if (ch[i] == 'A')
      c++;
    else
      d++;
  }
  if (c > d) {
    cout << "Anton" << endl;
  } else if (c < d) {
    cout << "Danik" << endl;
  } else
    cout << "Friendship" << endl;
}
