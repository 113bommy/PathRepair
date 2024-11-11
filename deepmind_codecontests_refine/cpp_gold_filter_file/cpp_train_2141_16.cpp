#include <bits/stdc++.h>
using namespace std;
int arr[27];
int a = 0;
int A_A = (int)'a';
queue<string> ss;
queue<int> indexs;
void get(char let) {
  string s = ss.front();
  ss.pop();
  int index = indexs.front();
  indexs.pop();
  int last = -1;
  int b = s.length();
  int temp = min(a, b);
  for (int x = index; x < temp; x++) {
    if (s[x] == let) {
      last = x;
    }
    if (s[x] < let) {
      arr[(int)s[x] - A_A]++;
      indexs.push(0);
      ss.push(s.substr(x + 1));
      return;
    }
  }
  if (last != -1 && a == temp)
    arr[(int)let - A_A]++;
  else
    return;
  if (last != b) {
    ss.push(s.substr(last + 1));
    indexs.push(temp - last - 1);
  }
}
int main() {
  string s;
  cin >> a;
  cin >> s;
  int l = s.length();
  bool check = true;
  char let;
  for (int x = 0; x < 26; x++) {
    check = true;
    int last = -1;
    for (int y = 0; y < s.length(); y++) {
      if ((int)s[y] - A_A <= x) {
        last = y;
      }
      if (y - last >= a) {
        check = false;
        break;
      }
    }
    if (check) {
      let = (char)(A_A + x);
      break;
    }
  }
  ss.push(s);
  indexs.push(0);
  while (!ss.empty()) {
    get(let);
  }
  for (int x = 0; x < 26; x++) {
    while (arr[x] > 0) {
      cout << (char)(A_A + x);
      arr[x]--;
    }
  }
  cout << endl;
}
