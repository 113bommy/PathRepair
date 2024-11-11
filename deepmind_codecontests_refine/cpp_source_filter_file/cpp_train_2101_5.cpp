#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    string cad1, cad2;
    cin >> cad1 >> cad2;
    int menos = 0;
    for (int i = cad2.size() - 1; i >= 0; i++) {
      if (cad2[i] == '1') {
        break;
      }
      menos++;
    }
    int mas = 0;
    for (int i = cad1.size() - 1 - menos; i >= 0; i--) {
      if (cad1[i] == '1') break;
      mas++;
    }
    cout << mas << endl;
  }
}
