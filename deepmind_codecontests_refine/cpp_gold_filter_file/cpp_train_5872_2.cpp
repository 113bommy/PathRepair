#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int INF = 2147483647;
const long long LLINF = 9223372036854775807;
int main() {
  int n, x;
  cin >> n >> x;
  if (n == 3) {
    cout << ">.v" << endl;
    cout << "..." << endl;
    cout << "^.<" << endl;
    cout << "1 1" << endl;
  } else if (n == 5) {
    cout << ">>.>v" << endl;
    cout << ".v.<<" << endl;
    cout << "^>.>v" << endl;
    cout << "^..<<" << endl;
    cout << "....." << endl;
    cout << "1 1" << endl;
  } else if (n == 100) {
    for (int i = 0; i < (33); i++) cout << ">";
    for (int i = 0; i < (33); i++) cout << ".>";
    cout << "v" << endl;
    for (int j = (0); j < (49); j++) {
      cout << "^v";
      for (int i = 0; i < (33); i++) cout << "<.";
      for (int i = 0; i < (32); i++) cout << "<";
      cout << endl << "^";
      for (int i = 0; i < (32); i++) cout << ">";
      for (int i = 0; i < (33); i++) cout << ".>";
      cout << "v" << endl;
    }
    cout << "^";
    for (int i = 0; i < (33); i++) cout << "<.";
    for (int i = 0; i < (33); i++) cout << "<";
    cout << endl;
    cout << "1 1" << endl;
  }
  return 0;
}
