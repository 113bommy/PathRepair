#include <bits/stdc++.h>
using namespace std;
char s1[] = {'^', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
             'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
             'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main() {
  int n;
  string s;
  cin >> s;
  cin >> n;
  for (int i = 0; i < s.size(); i++)
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
  for (int i = 0; i < s.size(); i++)
    if (s[i] < s1[n]) s[i] -= 32;
  cout << s;
  return 0;
}
