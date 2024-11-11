#include <bits/stdc++.h>
using namespace std;
void fast() { ios_base ::sync_with_stdio(false); }
int main() {
  long long n = 0;
  cin >> n;
  if (n % 2 == 0) {
    cout << "-1" << endl;
    return 0;
  } else {
    for (int i = 0; i < n; i++) {
      cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      cout << i * 2 % n << " ";
    }
    cout << endl;
  }
  return 0;
}
