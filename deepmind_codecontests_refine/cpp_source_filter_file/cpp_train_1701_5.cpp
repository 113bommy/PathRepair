#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y, z, m, k;
  cin >> n;
  map<string, long long int> input;
  map<long long int, long long int> last;
  input.clear();
  for (long long int i = 0; i < n; i++) {
    string s;
    cin >> s >> x;
    input[s] = max(input[s], x);
  }
  vector<long long int> chek;
  for (auto it : input) {
    chek.push_back(it.second);
  }
  sort((chek).begin(), (chek).end());
  for (long long int i = 0; i < chek.size(); i++) last[chek[i]] = i + 1;
  n = chek.size();
  cout << n << endl;
  for (auto it : input) {
    x = it.second;
    y = last[x];
    if (y * 100 >= n * 99)
      cout << it.first << " pro" << endl;
    else if (y * 100 >= n * 90)
      cout << it.first << " hardcore" << endl;
    else if (y * 100 >= n * 80)
      cout << it.first << " avarage" << endl;
    else if (y * 100 >= n * 50)
      cout << it.first << " random" << endl;
    else
      cout << it.first << " noob" << endl;
  }
}
