#include <bits/stdc++.h>
using namespace std;
int main() {
  bool katt = true;
  for (int i = 0; i < 6; ++i) {
    cout << i << endl;
    string s;
    getline(cin, s);
    if (s == "terrible") katt = false;
    if (s == "worse") katt = false;
    if (s == "don't even") katt = false;
    if (s == "are you serious") katt = false;
    if (s == "go die in a hole") katt = false;
  }
  if (katt == true)
    cout << "normal" << endl;
  else
    cout << "grumpy" << endl;
}
