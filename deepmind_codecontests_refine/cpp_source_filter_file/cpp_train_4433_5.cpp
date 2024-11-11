#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::string word;
  std::cin >> word;
  if (n % 4 != 0) {
    std::cout << "===";
  } else {
    int a = 0, c = 0, g = 0, t = 0, q = 0;
    int da = 0, dc = 0, dg = 0, dt = 0;
    for (int i = 0; i < word.size(); i++) {
      if (word[i] == 'A')
        a++;
      else if (word[i] == 'C')
        c++;
      else if (word[i] == 'G')
        g++;
      else if (word[i] == 'T')
        t++;
      else if (word[i] == '?')
        q++;
    }
    int max = std::max(a, std::max(c, std::max(g, t)));
    da = max - a;
    dg = max - g;
    dc = max - c;
    dt = max - t;
    int z = (q - da - dg - dc - dt);
    if (z < 0 || z % 4 != 0) {
      std::cout << "===";
    } else {
      z %= 4;
      da += z;
      dc += z;
      dg += z;
      dt += z;
      for (int i = 0; i < word.size(); i++) {
        if (word[i] == '?') {
          if (da > 0) {
            word[i] = 'A';
            da--;
          } else if (dc > 0) {
            word[i] = 'C';
            dc--;
          } else if (dg > 0) {
            word[i] = 'G';
            dg--;
          } else if (dt > 0) {
            word[i] = 'T';
            dt--;
          }
        }
      }
      std::cout << word;
    }
  }
  return 0;
}
