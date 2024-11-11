#include <bits/stdc++.h>
using namespace std;
int a[1010], b;
int main() {
  ios_base::sync_with_stdio();
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) {
    cin >> a[i] >> b;
    if (a[i] != b) {
      cout << "rated\n";
      return 0;
    }
  }
  int co = 1;
  for (int i = (0); i < (n - 1); i++) {
    if (a[i] < a[i + 1]) co = 0;
  }
  if (co == 0)
    cout << "maybe\n";
  else
    cout << "unrated\n";
  return 0;
}
