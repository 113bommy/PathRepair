#include <bits/stdc++.h>
using namespace std;
int a, b, black, white, d, ans;
double c;
string cheese, soft = "soft", hard = "hard";
int main() {
  cin >> a;
  for (int i = 0; i < a + 1; i++) {
    getline(cin, cheese);
    b = cheese.find(soft);
    if (b > 1) white++;
    b = 0;
    b = cheese.find(hard);
    if (b > 1) black++;
    b = 0;
    cheese.clear();
  }
  c = max(black, white);
  if (fmod(c, 2) > 0) {
    c--;
    d++;
  }
  c = c * 2;
  if (fmod((sqrt(c) * 10), 10) == 0 && d > 0) c++;
  while (fmod((sqrt(c) * 10), 10) > 0) c++;
  ans = sqrt(c);
  if (pow(ans, 2) < black + white) ans = black + white;
  cout << ans;
}
