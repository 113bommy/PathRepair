#include <bits/stdc++.h>
using namespace std;
void solution() {
  string st1, st2;
  cin >> st1 >> st2;
  long long int count1 = 0, count2 = 0;
  for (long long int i = 0; i < st1.size(); i++)
    if (st1[i] != st2[i]) {
      if (st1[i] = '4')
        count1++;
      else
        count2++;
    }
  cout << max(count1, count2);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long int testCases = 1;
  while (testCases--) solution();
}
