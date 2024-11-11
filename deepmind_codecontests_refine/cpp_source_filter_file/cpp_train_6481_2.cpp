#include <bits/stdc++.h>
using namespace std;
void fastrun() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
void noober() {
  long long int n, cnt = 0;
  cin >> n;
  long long int ar[n];
  for (long long int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (long long int i = 0; i < n; i++) {
    if (ar[i] == '1') {
      cnt++;
    } else {
      break;
    }
  }
  if (cnt == n) {
    cnt--;
  }
  if (cnt % 2) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
}
int main() {
  fastrun();
  long long int t;
  cin >> t;
  while (t--) {
    noober();
  }
  return 0;
}
