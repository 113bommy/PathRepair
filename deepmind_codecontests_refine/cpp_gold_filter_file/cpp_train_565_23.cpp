#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, t = 0;
  char ch[10000];
  int cnt[10000] = {0};
  scanf("%d", &num);
  scanf("%s", ch);
  for (int i = 0; i < strlen(ch); i++)
    if (ch[i] == 'T') t++;
  for (int i = 0; i < t; i++)
    if (ch[i] == 'T') cnt[0]++;
  int tm = cnt[0];
  for (int i = 1; i < strlen(ch); i++) {
    int tmp = cnt[i - 1];
    if (ch[i - 1] == 'T') tmp--;
    if (ch[(i + t - 1) % strlen(ch)] == 'T') tmp++;
    cnt[i] = tmp;
    tm = std::max(cnt[i], tm);
  }
  cout << t - tm << endl;
  return 0;
}
