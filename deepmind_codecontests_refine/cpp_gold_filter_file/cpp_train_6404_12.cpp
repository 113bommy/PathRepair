#include <bits/stdc++.h>
using namespace std;
int main() {
  char s1[1000], s2[1000];
  cin >> s1;
  cin >> s2;
  for (int i = 0; i < strlen(s1); i++)
    cout << (((int)s1[i] - 48) ^ ((int)s2[i] - 48));
}
