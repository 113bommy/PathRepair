#include <bits/stdc++.h>
using namespace std;
long n, q = 0, cnt = 0, z;
char s[4];
vector<bool> ty(200000, 0);
string ans;
bool go() {
  if (q >= z) return false;
  if (ty[q]) {
    ans += "pair";
    ans += "<";
    q++;
    if (!go()) return false;
    q++;
    ans += ",";
    if (!go()) return false;
    ans += ">";
  } else
    ans += "int";
  return true;
}
int main(int argc, char *argv[]) {
  cin >> n;
  long i = 0;
  while (scanf("%s", &s) != EOF) {
    if (cnt == n) return puts("Error occurred") & 0;
    if (s[0] == 'i') {
      cnt++;
      ty[i] = false;
    } else
      ty[i] = true;
    i++;
  }
  z = i;
  if (go() == false)
    puts("Error occurred");
  else if (q != z - 1)
    puts("Error occurred");
  else
    puts(ans.c_str());
  return EXIT_SUCCESS;
}
