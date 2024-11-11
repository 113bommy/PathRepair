#include <bits/stdc++.h>
using namespace std;
int main() {
  int times;
  cin >> times;
  while (times--) {
    int n, m;
    int notes[10000];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      int auxinput;
      cin >> auxinput;
      notes[i] = auxinput;
    }
    int mynote = notes[0];
    if (mynote == m) {
      cout << m << endl;
    } else {
      for (int i = 1; i < m && mynote < m; i++) {
        while (notes[i] > 0 && mynote != m) {
          mynote += 1;
          notes[i] -= 1;
        }
      }
      cout << mynote << endl;
    }
  }
}
