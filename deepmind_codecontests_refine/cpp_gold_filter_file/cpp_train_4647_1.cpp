#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
string words[MAXN];
bool order[26][26];
int incoming[26];
bool used[26];
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int N;
  cin >> N;
  for (int a = 0; a < N; a++) {
    cin >> words[a];
    set<char> letters;
    for (char c : words[a]) {
      used[c - 'a'] = true;
      if (letters.count(c)) {
        cout << "NO\n";
        return 0;
      } else {
        letters.insert(c);
      }
    }
  }
  for (int a = 0; a < N; a++) {
    for (int b = 1; b < (int)words[a].size(); b++) {
      order[words[a][b - 1] - 'a'][words[a][b] - 'a'] = true;
    }
  }
  for (int a = 0; a < 26; a++) {
    if (order[a][a]) {
      cout << "NO\n";
      return 0;
    }
    for (int b = 0; b < 26; b++) {
      if (order[a][b]) {
        incoming[b]++;
      }
    }
  }
  for (int a = 0; a < 26; a++) {
    int cnt = 0;
    for (int b = 0; b < 26; b++) {
      if (order[a][b]) {
        cnt++;
      }
    }
    if (cnt > 1 || incoming[a] > 1) {
      cout << "NO\n";
      return 0;
    }
  }
  string str = "";
  for (int a = 0; a < 26; a++) {
    if (used[a] && !incoming[a]) {
      int x = a;
      bool last = false;
      while (!last) {
        str += char(x + 'a');
        used[x] = false;
        last = true;
        for (int i = 0; i < 26; i++) {
          if (order[x][i]) {
            last = false;
            x = i;
            break;
          }
        }
      }
    }
  }
  for (int a = 0; a < 26; a++) {
    if (used[a]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << str;
}
