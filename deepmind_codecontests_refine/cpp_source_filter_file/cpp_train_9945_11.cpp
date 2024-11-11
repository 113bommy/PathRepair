#include <bits/stdc++.h>
using namespace std;
deque<string> q;
int main() {
  int i;
  string str, tmp;
  cin >> str >> tmp;
  str += tmp;
  for (i = 0; i < 15; i++) {
    if (str[0] == 'X') {
      swap(str[0], str[2]);
      q.push_back(str);
      swap(str[0], str[2]);
      swap(str[0], str[1]);
      q.push_back(str);
    }
    if (str[1] == 'X') {
      swap(str[1], str[0]);
      q.push_back(str);
      swap(str[1], str[0]);
      swap(str[1], str[3]);
      q.push_back(str);
    }
    if (str[3] == 'X') {
      swap(str[3], str[1]);
      q.push_back(str);
      swap(str[3], str[1]);
      swap(str[3], str[2]);
      q.push_back(str);
    }
    if (str[2] == 'X') {
      swap(str[2], str[3]);
      q.push_back(str);
      swap(str[2], str[3]);
      swap(str[2], str[0]);
      q.push_back(str);
    }
  }
  cin >> str >> tmp;
  str += tmp;
  for (i = 0; i < 15; i++)
    if (q[i] == str) {
      puts("YES");
      return 0;
    }
  puts("NO");
}
