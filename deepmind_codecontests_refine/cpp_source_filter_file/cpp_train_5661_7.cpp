#include <bits/stdc++.h>
using namespace std;
string num;
int now;
bool ch = 0;
int main() {
  cin >> num;
  for (int i = 0; i < num.size(); i++) {
    if (num[i] == '0') {
      now = i;
      ch = true;
    }
    if (ch) break;
  }
  if (!ch) {
    for (int i = 0; i < num.size() - 1; i++) cout << num[i];
    return 0;
  }
  for (int i = 0; i < now; i++) cout << num[i];
  for (int i = now + 1; i <= num.size(); i++) cout << num[i];
}
