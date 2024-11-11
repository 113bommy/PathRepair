#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  map<int, int> students;
  vector<int> values;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> k;
    students.insert(make_pair(i, 0));
    values.push_back(k);
  }
  long long int pos = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      students[j] = 0;
    }
    pos = i;
    while (true) {
      students[pos] += 1;
      if (students[pos] == 2) {
        cout << pos + 1 << " ";
        break;
      }
      pos = values[pos] - 1;
    }
  }
  cout << "\n";
  return 0;
}
