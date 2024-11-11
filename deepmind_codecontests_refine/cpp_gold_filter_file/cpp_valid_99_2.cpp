#include <bits/stdc++.h>
using namespace std;
int str[210][210] = {0};
int t;
set<int> st;
vector<int> vi;
void init() {
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < t; j++) str[i][j] = 0;
    str[i][i] = -2;
  }
  st.clear(), vi.clear();
}
void decode(int s) {
  if (s == 0) printf("=");
  if (s == 1) printf("+");
  if (s == -1) printf("-");
  if (s == -2) printf("X");
}
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    string s;
    cin >> t >> s;
    init();
    for (int i = 0; i < t; i++) {
      if (s[i] == '1')
        st.insert(i);
      else
        vi.push_back(i);
    }
    int len = vi.size();
    int cnt = 0;
    for (int i = 0; i < t; i++) {
      if (s[i] == '2') {
        str[i][vi[(cnt + 1) % len]] = 1;
        str[vi[(cnt + 1) % len]][i] = -1;
        cnt++;
      }
    }
    if (len < 3 && len) {
      printf("NO\n");
    } else {
      printf("YES\n");
      for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
          decode(str[i][j]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
