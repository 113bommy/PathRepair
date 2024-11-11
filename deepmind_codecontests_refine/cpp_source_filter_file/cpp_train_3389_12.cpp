#include <bits/stdc++.h>
using namespace std;
set<char> Set;
int main() {
  Set.insert('C');
  Set.insert('M');
  Set.insert('Y');
  Set.insert('W');
  Set.insert('G');
  Set.insert('B');
  int n, m;
  scanf("%d%d", &n, &m);
  string st;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    getline(cin, st);
    int len = st.length();
    for (int j = 0; j < len; j++) {
      if (Set.find(st[j]) != Set.end())
        sum += (st[j] == 'C') + (st[j] == 'M') + (st[j] == 'Y');
    }
  }
  if (sum != 0)
    printf("#Color\n");
  else
    printf("#Black&White\n");
  return 0;
}
