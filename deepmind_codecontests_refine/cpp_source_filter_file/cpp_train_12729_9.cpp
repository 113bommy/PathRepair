#include <bits/stdc++.h>
int main() {
  std::string guest, host, pile;
  std::cin >> guest >> host >> pile;
  int arr[26];
  for (unsigned i = 0; i < pile.size(); i++) arr[pile[i] - 65]++;
  for (unsigned i = 0; i < guest.size(); i++) arr[guest[i] - 65]--;
  for (unsigned i = 0; i < host.size(); i++) arr[host[i] - 65]--;
  bool isUsedUp = true;
  for (unsigned i = 0; i < 26; i++)
    if (arr[i] != 0) {
      isUsedUp = false;
      break;
    }
  if (isUsedUp)
    std::cout << "YES";
  else
    std::cout << "NO";
  return 0;
}
