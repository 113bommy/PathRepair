#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int temp;
  vector<int> persons;
  vector<int>::iterator it;
  for (int i = 1; i <= n; i++) persons.push_back(i);
  int leader = 0;
  while (k--) {
    cin >> temp;
    temp = temp % n;
    cout << persons[(leader + temp) % n] << " ";
    int cnt = 0;
    for (it = persons.begin(); it != persons.end(); it++)
      if (cnt == (leader + temp) % n)
        break;
      else
        cnt++;
    persons.erase(it);
    leader = (leader + temp) % n;
    n--;
  }
  cout << "\n";
  return 0;
}
