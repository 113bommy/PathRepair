#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
void __never(int a) { printf("\nOPS %d", a); }
int n;
int A[100100];
bool F[100100];
vector<vector<int> > v;
vector<vector<int> > four_five;
vector<vector<int> > two;
vector<vector<int> > three;
void sol() {
  for (int a = (1); a <= (n); a++)
    if (!F[a]) {
      vector<int> tmp;
      int cur = a;
      while (1) {
        F[cur] = true;
        tmp.push_back(cur);
        cur = A[cur];
        if (F[cur]) break;
      }
      v.push_back(tmp);
    }
  for (int a = (0); a <= ((int)((v).size()) - 1); a++) {
    if ((int)((v[a]).size()) >= 4) {
      vector<int> tmp;
      for (int b = (0); b <= ((int)((v[a]).size()) - 1); b++) {
        tmp.push_back(v[a][b]);
        if ((int)((tmp).size()) == 5) {
          four_five.push_back(tmp);
          tmp.clear();
          tmp.push_back(v[a][0]);
        }
      }
      if ((int)((tmp).size()) == 4)
        four_five.push_back(tmp);
      else if ((int)((tmp).size()) == 3)
        three.push_back(tmp);
      else if ((int)((tmp).size()) == 2)
        two.push_back(tmp);
    } else if ((int)((v[a]).size()) == 3)
      three.push_back(v[a]);
    else if ((int)((v[a]).size()) == 2)
      two.push_back(v[a]);
  }
  int ans4_5 = (int)((four_five).size());
  int ans32 = min((int)((two).size()), (int)((three).size()));
  int ans22 = ((int)((two).size()) - ans32) / 2;
  int ans2 = ((int)((two).size()) - ans32) % 2;
  int ans3 = 2 * (((int)((three).size()) - ans32) / 3) +
             ((int)((three).size()) - ans32) % 3;
  int ans = ans4_5 + ans32 + ans22 + ans2 + ans3;
  cout << ans << "\n";
  for (int a = (0); a <= ((int)((four_five).size()) - 1); a++) {
    vector<int> v = four_five[a];
    if ((int)((v).size()) == 5) {
      printf("5\n");
      printf("%d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4]);
      printf("%d %d %d %d %d\n", v[1], v[2], v[3], v[4], v[0]);
    } else {
      printf("4\n");
      printf("%d %d %d %d\n", v[0], v[1], v[2], v[3]);
      printf("%d %d %d %d\n", v[1], v[2], v[3], v[0]);
    }
  }
  for (int a = (0); a <= (ans32 - 1); a++) {
    vector<int> v2 = two[a];
    vector<int> v3 = three[a];
    printf("5\n");
    printf("%d %d %d %d %d\n", v2[0], v2[1], v3[0], v3[1], v3[2]);
    printf("%d %d %d %d %d\n", v2[1], v2[0], v3[1], v3[2], v3[0]);
  }
  for (int a = ans32; a + 2 < (int)((three).size()); a += 3) {
    vector<int> v = three[a];
    vector<int> vv = three[a + 1];
    vector<int> vvv = three[a + 2];
    printf("5\n");
    printf("%d %d %d %d %d\n", v[0], v[1], v[2], vvv[0], vvv[1]);
    printf("%d %d %d %d %d\n", v[1], v[2], v[0], vvv[1], vvv[0]);
    printf("5\n");
    printf("%d %d %d %d %d\n", vv[0], vv[1], vv[2], vvv[0], vvv[2]);
    printf("%d %d %d %d %d\n", vv[1], vv[2], vv[0], vvv[2], vvv[0]);
  }
  for (int a = (ans32 + (((int)((three).size()) - ans32) / 3) * 3);
       a <= ((int)((three).size()) - 1); a++) {
    vector<int> v3 = three[a];
    printf("3\n");
    printf("%d %d %d\n", v3[0], v3[1], v3[2]);
    printf("%d %d %d\n", v3[1], v3[2], v3[0]);
  }
  for (int a = ans32; a + 1 < (int)((two).size()); a += 2) {
    vector<int> v = two[a];
    vector<int> vv = two[a + 1];
    printf("4\n");
    printf("%d %d %d %d\n", v[0], v[1], vv[0], vv[1]);
    printf("%d %d %d %d\n", v[1], v[0], vv[1], vv[0]);
  }
  if (ans2) {
    vector<int> v = two[(int)((two).size()) - 1];
    printf("2\n");
    printf("%d %d\n", v[0], v[1]);
    printf("%d %d\n", v[1], v[0]);
  }
}
int main() {
  scanf("%d", &n);
  for (int a = (1); a <= (n); a++) scanf("%d", &A[a]);
  sol();
  return 0;
}
