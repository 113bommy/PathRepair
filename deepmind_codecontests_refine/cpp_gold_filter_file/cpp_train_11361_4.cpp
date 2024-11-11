#include <bits/stdc++.h>
using namespace std;
char ch[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
               'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a = n / k + n % k;
    int b = n / k;
    for (int i = 0; i < a; i++) {
      cout << ch[0];
    }
    for (int i = 1; i < k; i++) {
      for (int j = 0; j < b; j++) {
        cout << ch[i];
      }
    }
    cout << endl;
  }
}
