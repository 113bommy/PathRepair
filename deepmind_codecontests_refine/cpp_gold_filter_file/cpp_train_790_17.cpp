#include <bits/stdc++.h>
using namespace std;
char s[100010][10];
int type[100010], mark[100010];
string random_file() {
  string res;
  for (int i = 0; i < 6; i++) res += 'a' + rand() % 26;
  return res;
}
char tmp[100];
vector<string> ans;
void print(const char* src, const char* dest) {
  sprintf(tmp, "move %s %s\n", src, dest);
  ans.push_back(tmp);
}
void print(const char* src, const int dest) {
  sprintf(tmp, "move %s %d\n", src, dest);
  ans.push_back(tmp);
}
void print(const int src, const char* dest) {
  sprintf(tmp, "move %d %s\n", src, dest);
  ans.push_back(tmp);
}
int main() {
  int n;
  scanf("%d", &n);
  int e = 0;
  set<string> str;
  for (int i = 1; i <= n; i++) {
    scanf("%s%d", s[i], &type[i]);
    str.insert(s[i]);
    if (type[i] == 1) e++;
  }
  vector<int> toback, tofront, front, back, tofront2, toback2;
  for (int i = 1; i <= n; i++) {
    int j = atoi(s[i]);
    char tmp[20];
    sprintf(tmp, "%d", j);
    if (j > 0 && j <= n && strcmp(tmp, s[i]) == 0) {
      if (type[i] == 0) {
        if (j <= e) {
          toback.push_back(i);
        }
      } else {
        if (j > e) {
          tofront.push_back(i);
        }
      }
      mark[j] = 1;
    } else {
      if (type[i] == 0) {
        toback2.push_back(i);
      } else {
        tofront2.push_back(i);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) {
      if (i <= e) {
        front.push_back(i);
      } else {
        back.push_back(i);
      }
    }
  }
  if (front.size() == 0 && back.size() == 0) {
    string temp_file = random_file();
    while (str.count(temp_file)) temp_file = random_file();
    if (tofront.size() != 0) {
      int i = tofront.back();
      print(s[i], temp_file.c_str());
      back.push_back(atoi(s[i]));
      strcpy(s[i], temp_file.c_str());
      tofront2.push_back(i);
      tofront.pop_back();
    }
  }
  if (front.size() > 0) {
    while (tofront.size() > 0 && toback.size() > 0) {
      int i = atoi(s[toback.back()]);
      print(s[tofront.back()], front.back());
      print(s[toback.back()], s[tofront.back()]);
      tofront.pop_back();
      front.pop_back();
      front.push_back(i);
      toback.pop_back();
    }
  }
  if (back.size() > 0) {
    while (tofront.size() > 0 && toback.size() > 0) {
      int i = atoi(s[tofront.back()]);
      print(s[toback.back()], back.back());
      print(s[tofront.back()], s[toback.back()]);
      toback.pop_back();
      tofront.pop_back();
      back.pop_back();
      back.push_back(i);
    }
  }
  while (tofront.size() > 0) {
    print(s[tofront.back()], front.back());
    back.push_back(atoi(s[tofront.back()]));
    front.pop_back();
    tofront.pop_back();
  }
  while (toback.size() > 0) {
    print(s[toback.back()], back.back());
    front.push_back(atoi(s[toback.back()]));
    back.pop_back();
    toback.pop_back();
  }
  for (auto i : tofront2) {
    print(s[i], front.back());
    front.pop_back();
  }
  for (auto i : toback2) {
    print(s[i], back.back());
    back.pop_back();
  }
  printf("%d\n", ans.size());
  for (auto l : ans) cout << l;
  return 0;
}
