#include <bits/stdc++.h>
std::string found = "";
bool f = false;
void cp(std::string x) {
  int len = x.length() - 1 / 2;
  int bp = x.length() - 1;
  int c = 0;
  for (int i = 0; i < len; i++) {
    if (x.at(i) == x.at(bp)) {
      c++;
    } else
      break;
    bp--;
  }
  if (c == len) {
    found = x;
    f = true;
  }
}
int main() {
  std::string p;
  std::cin >> p;
  for (int i = 0; i <= p.length(); i++) {
    for (int j = 'a'; j <= 'z'; j++) {
      std::string ts(1, j);
      p.insert(i, ts);
      cp(p);
      p.erase(i, 1);
    }
  }
  if (f) {
    std::cout << found;
  } else {
    std::cout << "NA";
  }
  getchar();
  getchar();
  return 0;
}
