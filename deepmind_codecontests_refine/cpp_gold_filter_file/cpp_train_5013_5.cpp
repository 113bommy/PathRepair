#include <bits/stdc++.h>
using namespace std;
char str[105];
int asc[127];
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    string s1, s2;
    scanf("%s", str);
    memset(asc, 0, sizeof(asc));
    for (int i = 0; str[i]; i++) asc[str[i]]++;
    for (int i = 'a'; i <= 'z'; i += 2)
      while (asc[i]--) s1 += i;
    for (int i = 'b'; i <= 'z'; i += 2)
      while (asc[i]--) s2 += i;
    if (abs((*s1.begin()) - (*(s2.end() - 1))) > 1)
      cout << s2 << s1 << endl;
    else if (abs((*(s1.end() - 1)) - (*s2.begin())) > 1)
      cout << s1 << s2 << endl;
    else
      cout << "No answer" << endl;
  }
  return 0;
}
