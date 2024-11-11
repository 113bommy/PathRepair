#include <bits/stdc++.h>
using namespace std;
int read() {
  int n;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s;
  return n;
}
int main() {
  cout << "next 0 1" << endl;
  cout.flush();
  read();
  cout << "next 1" << endl;
  cout.flush();
  while (read() == 3) {
    cout << "next 0 1" << endl;
    cout.flush();
    read();
    cout << "next 1" << endl;
    cout.flush();
  }
  cout << "next" << endl;
  for (int i = 0; i < 10; i++) cout << " " << i;
  cout << endl;
  cout.flush();
  while (read() == 2) {
    cout << "next";
    for (int i = 0; i < 10; i++) cout << " " << i;
    cout << endl;
    cout.flush();
  }
  cout << "done" << endl;
  cout.flush();
}
