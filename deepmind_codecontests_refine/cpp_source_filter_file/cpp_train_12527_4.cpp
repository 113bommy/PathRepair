#include <bits/stdc++.h>
using namespace std;
struct F {
  string Name;
  string Ext;
} File[400032];
char buf[400032];
string s;
int n;
string lastext;
int main() {
  scanf("%s", buf);
  s = buf;
  n = s.size();
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '.' && s[i + 1] == '.') {
      puts("NO");
      return 0;
    }
  }
  int pos = 0;
  int now = 0;
  while (s[pos] != '.' && pos < n) {
    File[now].Name += s[pos];
    pos++;
  }
  if (pos >= 8 || pos == n || pos == 0) {
    puts("NO");
    return 0;
  }
  pos++;
  int len = 0;
  int end = n - 1;
  while (s[end] != '.' && end >= 0) {
    lastext = s[end] + lastext;
    end--;
  }
  if (lastext.size() > 3 || lastext.size() < 1) {
    puts("NO");
    return 0;
  }
  while (pos < end) {
    string part;
    while (s[pos] != '.' && pos < n) {
      part += s[pos];
      pos++;
    }
    int npart = part.size();
    if (npart > 11 || npart < 2) {
      puts("NO");
      return 0;
    }
    if (npart < 4) {
      File[now].Ext = part.substr(0, 1);
      File[++now].Name = part.substr(1, part.size() - 1);
    } else {
      File[now].Ext = part.substr(0, 3);
      File[++now].Name = part.substr(3, part.size() - 1);
    }
    pos++;
  }
  File[now].Ext = lastext;
  puts("YES");
  for (int i = 0; i <= now; i++) {
    string file = File[i].Name + '.' + File[i].Ext;
    printf("%s\n", file.c_str());
  }
  return 0;
}
