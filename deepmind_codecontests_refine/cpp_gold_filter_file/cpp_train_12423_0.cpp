#include <bits/stdc++.h>
using namespace std;
int l;
string txt, txt2;
bool cmp(char a, char b) { return (a > b); }
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> txt >> txt2;
  sort(txt2.begin(), txt2.end(), cmp);
  for (int i = 0; i < txt.size(); i++)
    if (txt2[l] > txt[i] && l < txt.size()) txt[i] = txt2[l], l++;
  return cout << txt << endl, 0;
}
