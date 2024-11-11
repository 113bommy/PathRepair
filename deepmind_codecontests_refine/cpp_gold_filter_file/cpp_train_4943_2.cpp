#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v, p;
  p.push_back(0);
  string in, second = "", x = "";
  while (cin >> in) second += in;
  for (int i = 0; i < second.size();) {
    int j = i;
    while (second[j] != '>')
      if (++j >= second.size()) break;
    ++j;
    x = second.substr(i, j - i);
    if (x == "<table>")
      v.push_back(0), p.push_back(v.size() - 1);
    else if (x == "</table>")
      p.pop_back();
    else if (x == "<td>")
      v[p[p.size() - 1]] += 1;
    i = j;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size() - 1; i++) cout << v[i] << " ";
  cout << v[v.size() - 1];
}
