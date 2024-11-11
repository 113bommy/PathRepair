#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++) cout << (i % 2 == 0 ? "aa" : "bb");
    cout << endl;
    cout << "c";
    for (int i = 0; i < n / 2 - 1; i++) cout << (i % 2 == 0 ? "dd" : "ee");
    cout << "f";
    cout << endl;
    cout << "c";
    for (int i = 0; i < n / 2 - 1; i++) cout << (i % 2 == 0 ? "gg" : "hh");
    cout << "f";
    cout << endl;
    for (int i = 0; i < n / 2; i++) cout << (i % 2 == 0 ? "aa" : "bb");
    cout << endl;
  } else {
    cout << "c";
    for (int i = 0; i < n / 2; i++) cout << (i % 2 == 0 ? "dd" : "ee");
    cout << endl;
    cout << "c";
    for (int i = 0; i < n / 2; i++) cout << (i % 2 == 0 ? "ee" : "dd");
    cout << endl;
    for (int i = 0; i < n / 2; i++) cout << (i % 2 == 0 ? "gg" : "hh");
    cout << "f";
    cout << endl;
    for (int i = 0; i < n / 2; i++) cout << (i % 2 == 0 ? "hh" : "gg");
    cout << "f";
    cout << endl;
  }
  return 0;
}
