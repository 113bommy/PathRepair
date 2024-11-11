#include <bits/stdc++.h>
using namespace std;
int nimbers[5050];
void compute_nimbers() {
  bool poss[5050];
  nimbers[0] = 0;
  nimbers[1] = 1;
  for (int i = 2; i <= 5000; i++) {
    for (int j = 0; j <= 5000; j++) poss[j] = false;
    for (int j = 1; j <= i; j++) {
      if (j == 1 || j == i)
        poss[nimbers[i - 2]] = true;
      else {
        int left = nimbers[j - 1 - 1];
        int right = nimbers[i - j - 1];
        poss[left ^ right] = true;
      }
    }
    int first = 0;
    while (poss[first]) first++;
    nimbers[i] = first;
  }
}
int eval(string s) {
  int nim = 0;
  int size = s.size();
  int len = 0;
  for (int i = 0; i < size; i++) {
    if (s[i] == '1')
      len++;
    else {
      nim ^= nimbers[len];
      len = 0;
    }
  }
  nim ^= nimbers[len];
  return nim;
}
int main() {
  compute_nimbers();
  string T;
  cin >> T;
  int size = T.size();
  string S(size, '0');
  S[0] = '0';
  for (int i = 1; i < size - 1; i++) {
    if (T[i - 1] == T[i + 1])
      S[i] = '1';
    else
      S[i] = '0';
  }
  S[size - 1] = '0';
  if (eval(S) == 0)
    cout << "Second\n";
  else {
    cout << "First\n";
    for (int i = 1; i < size - 1; i++) {
      if (S[i] == '0') continue;
      string left = S.substr(0, i);
      string right = S.substr(i + 1);
      left[i - 1] = '0';
      right[0] = '0';
      if (((eval(left)) ^ (eval(right))) == 0) {
        cout << i + 1 << endl;
        return 0;
      }
    }
  }
  return 0;
}
