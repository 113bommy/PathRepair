#include <bits/stdc++.h>
int main(void) {
  std::unordered_set<std::string> normal;
  std::unordered_set<std::string> grumpy;
  normal.insert(std::string("great!"));
  normal.insert(std::string("don\'t think so"));
  normal.insert(std::string("don\'t touch me!"));
  normal.insert(std::string("not bad"));
  normal.insert(std::string("cool"));
  grumpy.insert(std::string("don\'t even"));
  grumpy.insert(std::string("are you serious?"));
  grumpy.insert(std::string("go die in a hole"));
  grumpy.insert(std::string("worse"));
  grumpy.insert(std::string("terrible"));
  grumpy.insert(std::string("no way"));
  std::string ans = "normal";
  char response[100];
  for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
    fflush(stdout);
    gets(response);
    const std::string &res = response;
    if (normal.count(res)) {
      ans = "normal";
      break;
    } else if (grumpy.count(res)) {
      ans = "grumpy";
      break;
    }
  }
  printf("%s\n", ans.c_str());
  fflush(stdout);
  return 0;
}
