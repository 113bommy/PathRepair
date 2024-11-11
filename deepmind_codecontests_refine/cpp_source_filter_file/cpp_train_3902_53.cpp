#include <bits/stdc++.h>
using namespace std;
void situation1(int Length);
void situation2(int Length);
void situation3(int Length);
int main(void) {
  int Lines = 0;
  int Length = 0;
  int x = 0;
  cin >> Lines >> Length;
  for (int I = 0; I < Lines; I++) {
    if (I % 2 == 0) {
      situation1(Length);
      cout << "\n";
    } else if (I % 2 == 1) {
      if (x % 2 == 0) {
        situation2(Length);
        cout << "\n";
        x = x + 1;
      } else if (x % 2 == 1) {
        situation3(Length);
        cout << "\n";
        x = x + 1;
      }
    }
  }
}
void situation1(int Length) {
  for (int I = 0; I < Length; I++) {
    cout << "#";
  }
}
void situation2(int Length) {
  cout << "#";
  for (int I = 0; I < Length - 1; I++) {
    cout << ".";
  }
}
void situation3(int Length) {
  for (int I = 0; I < Length - 1; I++) {
    cout << ".";
  }
  cout << "#";
}
