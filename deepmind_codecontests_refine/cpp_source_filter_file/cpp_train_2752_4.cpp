#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
  cin >> N;
  int o;
  int crimes = 0;
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    if (temp > 0) {
      o += temp;
    } else if (temp == -1) {
      if (o >= 1) {
        o--;
      } else {
        crimes++;
      }
    }
  }
  cout << crimes;
}
