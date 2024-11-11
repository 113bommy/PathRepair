#include <bits/stdc++.h>
using namespace std;
void out() {
  cout << -1;
  exit(0);
}
int main() {
  int v1, v2, v3, v4;
  cin >> v1 >> v2 >> v3 >> v4;
  for (int s1 = 1; s1 < 220; s1++) {
    for (int s2 = 1; s2 < s1; s2++) {
      for (int s3 = 1; s3 < s2; s3++) {
        if (v1 <= s1 and v1 * 2 >= s1)
          if (v2 <= s2 and v2 * 2 >= s2)
            if (v3 <= s3 and v3 * 2 >= s3)
              if (v4 <= s3 and v4 * 2 >= s3)
                if (v4 * 2 <= s2) {
                  cout << s1 << "\n" << s2 << "\n" << s3;
                  return 0;
                }
      }
    }
  }
  cout << -1;
  return 0;
}
