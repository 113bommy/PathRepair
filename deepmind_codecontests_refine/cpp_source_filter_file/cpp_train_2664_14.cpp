#include <bits/stdc++.h>
using namespace std;
char rainbow[] = {'V', 'I', 'B', 'G', 'Y', 'O', 'R'};
char constraint[] = {'G', 'V', 'I', 'B'};
vector<char> solution;
int main() {
  int n, rem;
  cin >> n;
  solution.resize(n);
  rem = n % 7;
  for (int i = 0; i < rem; i++) {
    solution[solution.size() - 1 - i] = constraint[i % 4];
  }
  int temp = n - rem;
  for (int i = 0; i < temp; i++) {
    solution[i] = rainbow[i % 7];
  }
  for (int i = 0; i < solution.size(); i++) {
    cout << solution[i];
  }
}
