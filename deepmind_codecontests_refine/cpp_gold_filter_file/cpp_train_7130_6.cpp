#include <bits/stdc++.h>
using namespace std;
int main() {
  int age, count = 0, n;
  char buffer[101];
  string alc[12] = {"ABSINTH", "BEER",    "BRANDY", "CHAMPAGNE", "GIN", "RUM",
                    "SAKE",    "TEQUILA", "VODKA",  "WHISKEY",   "WINE"};
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%s", buffer);
    char* p;
    long converted = std::strtol(buffer, &p, 10);
    if (*p) {
      if (find(alc, alc + 12, buffer) != alc + 12) count++;
    } else {
      if (converted < 18) count++;
    }
  }
  cout << count << endl;
  return 0;
}
