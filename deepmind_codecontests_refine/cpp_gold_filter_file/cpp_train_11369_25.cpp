#include <bits/stdc++.h>
using namespace std;
struct xmltag {
  char name;
  bool open;
  int level;
};
int main() {
  int i, j, p, level;
  bool in;
  xmltag tag;
  xmltag arr[1000];
  stack<xmltag> st;
  string line;
  getline(cin, line);
  i = p = level = 0;
  while (i < line.length()) {
    if (line[i] == '<') {
      if (line[i + 1] == '/') {
        tag.open = false;
        tag.name = line[i + 2];
        i += 4;
        if (st.top().name == tag.name && st.top().open == true) {
          tag.level = --level;
          st.pop();
        }
        arr[p++] = tag;
      } else {
        tag.open = true;
        tag.name = line[i + 1];
        tag.level = level++;
        i += 3;
        st.push(tag);
        arr[p++] = tag;
      }
    }
  }
  for (i = 0; i < p; i++) {
    if (arr[i].level != 0) {
      for (j = 1; j <= 2 * arr[i].level; j++) {
        cout << " ";
      }
    }
    if (arr[i].open) {
      cout << "<" << arr[i].name << ">" << endl;
    } else {
      cout << "<"
           << "/" << arr[i].name << ">" << endl;
    }
  }
  return 0;
}
