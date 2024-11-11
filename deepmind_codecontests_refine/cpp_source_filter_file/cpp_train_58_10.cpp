#include <bits/stdc++.h>
using namespace std;
string lower(string s) {
  for (int i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
  return s;
}
vector<string> sep(string s, char c) {
  string temp;
  vector<string> res;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c) {
      if (temp != "") res.push_back(temp);
      temp = "";
      continue;
    }
    temp = temp + s[i];
  }
  if (temp != "") res.push_back(temp);
  return res;
}
template <class T>
T toint(string s) {
  stringstream ss(s);
  T ret;
  ss >> ret;
  return ret;
}
template <class T>
string tostr(T inp) {
  string ret;
  stringstream ss;
  ss << inp;
  ss >> ret;
  return ret;
}
template <class T>
void D(T A[], int n) {
  for (int i = 0; i < n; i++) cout << A[i] << " ";
  cout << endl;
}
template <class T>
void D(vector<T> A, int n = -1) {
  if (n == -1) n = A.size();
  for (int i = 0; i < n; i++) cout << A[i] << " ";
  cout << endl;
}
char buf[101];
int mem[111];
int main() {
  int t, m;
  int cnt = 0;
  scanf("%d %d", &t, &m);
  memset(mem, -1, sizeof(mem));
  for (int(cs) = (0); (cs) < (t); (cs)++) {
    int rsize;
    scanf("%s", &buf);
    if (strcmp(buf, "alloc") == 0) {
      scanf("%d", &rsize);
      int size = 0;
      int saddr = -1;
      for (int(i) = (0); (i) < (m); (i)++) {
        if (mem[i] != -1) {
          size = 0;
          continue;
        }
        size++;
        if (size == rsize) {
          saddr = i - (size - 1);
          break;
        }
      }
      if (saddr != -1) {
        ++cnt;
        for (int(i) = (0); (i) < (rsize); (i)++) mem[saddr + i] = cnt;
        printf("%d\n", cnt);
      } else
        puts("NULL");
    }
    if (strcmp(buf, "erase") == 0) {
      int addr;
      scanf("%d", &addr);
      bool erased = 0;
      if (addr)
        for (int(i) = (0); (i) < (m); (i)++)
          if (mem[i] == addr) {
            erased = 1;
            mem[i] = -1;
          }
      if (!erased) puts("ILLEGAL_ERASE_ARGUMENT");
    }
    if (strcmp(buf, "defragment") == 0) {
      int sp = 0;
      for (int i = 0; i < m; i++) {
        if (mem[i] == -1) continue;
        mem[sp++] = mem[i];
      }
      for (int(i) = (sp); (i) < (m); (i)++) mem[i] = -1;
    }
  }
  return 0;
}
