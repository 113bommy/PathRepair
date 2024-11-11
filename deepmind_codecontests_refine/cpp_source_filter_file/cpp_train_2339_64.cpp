#include <bits/stdc++.h>
using namespace std;
pair<string, string> a[3] = {{"", "F"}, {"", "M"}, {"", "S"}};
bool rec(int i) {
  if (i == 3) {
    if (a[0].first == "rock" && a[1].first == "scissors" &&
        a[2].first == "scisors") {
      return 1;
    }
    if (a[0].first == "paper" && a[1].first == "rock" && a[2].first == "rock") {
      return 1;
    }
    if (a[0].first == "scissors" && a[1].first == "paper" &&
        a[2].first == "paper") {
      return 1;
    }
    return 0;
  }
  for (int j = i; j < 3; j++) {
    swap(a[i], a[j]);
    if (rec(i + 1)) {
      return 1;
    }
    swap(a[i], a[j]);
  }
  return 0;
}
int main() {
  for (auto &i : a) {
    cin >> i.first;
  }
  if (rec(0)) {
    cout << a[0].second;
  } else {
    cout << "?";
  }
  return 0;
}
