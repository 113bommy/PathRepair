#include <bits/stdc++.h>
using namespace std;
int main() {
  int Current = 1, Destination, Tasks, Number, Time = 0;
  cin >> Number >> Tasks;
  for (int i = 0; i < Tasks; i++) {
    cin >> Destination;
    if (Destination > Current) {
      Time += Destination - Current;
    } else if (Current != Destination) {
      Time += Number - Current + Destination;
    }
    Current = Destination;
  }
  cout << Time << "\n";
  return 0;
}
