#include <bits/stdc++.h>
int in() {
  int r = 0, c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') return -in();
  for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar())
    ;
  return r;
}
using namespace std;
const int INF = int(1e9 + 7);
int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<pair<char, int> > word;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    int x = 0;
    while (s[i] == c && i < n) {
      x++;
      i++;
    }
    i--;
    word.push_back(make_pair(c, min(x, 2)));
  }
  n = word.size();
  for (int i = 0; i < n - 1; i++) {
    if (word[i].second == word[i + 1].second && word[i].second == 2)
      word[i + 1].second = 1;
  }
  for (int i = 0; i < n; i++) {
    while (word[i].second--) {
      cout << word[i].first;
    }
  }
  cout << endl;
  return 0;
}
