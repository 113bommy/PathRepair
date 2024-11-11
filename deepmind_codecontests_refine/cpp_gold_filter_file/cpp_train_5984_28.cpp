#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  long long mas[270];
  for (int i = 0; i < 270; i++) mas[i] = 0;
  long long count = 0;
  getline(cin, str);
  for (int i = 0; i < str.length(); i++) mas[str[i]]++;
  for (int i = 0; i < 270; i++) count += mas[i] * mas[i];
  cout << count << endl;
}
