#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265358979323843;
void Time() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void print(int n) {
  if (n == 0) {
    return;
  }
  print(n - 1);
  cout << "Hello world" << endl;
}
long long arr[100000];
int main() {
  Time();
  string s;
  int A = 0, B = 0, C = 0;
  for (int i = 0; i < 3; i++) {
    cin >> s;
    if (s[0] == 'A' && s[1] == '>' || s[2] == 'A' && s[1] == '<') {
      A++;
    } else if (s[0] == 'B' && s[1] == '>' || s[2] == 'B' && s[1] == '<') {
      B++;
    } else if (s[0] == 'C' && s[1] == '>' || s[2] == 'C' && s[1] == '<') {
      C++;
    }
  }
  if (A == B && A == C) {
    cout << "Impossible" << endl;
  } else if (A > B && A > C && B > C) {
    cout << "CBA" << endl;
  } else if (A > B && A > C && C > B) {
    cout << "BCA" << endl;
  } else if (B > A && B > C && A > C) {
    cout << "CAB" << endl;
  } else if (B > A && B > C && C > A) {
    cout << "ACB" << endl;
  } else if (C > A && C > B && A > B) {
    cout << "BAC" << endl;
  } else if (C > A && C > B && B > A) {
    cout << "ABC" << endl;
  }
  return 0;
}
