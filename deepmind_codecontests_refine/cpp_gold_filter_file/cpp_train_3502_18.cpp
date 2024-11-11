#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  map<string, string> a;
  for (int i = 0; i < n; i++) {
    string temp1, temp2;
    cin >> temp1 >> temp2;
    a.insert(pair<string, string>(temp2 + ";", temp1));
  }
  for (int i = 0; i < m; i++) {
    string command, ip;
    cin >> command >> ip;
    if (a.count(ip)) {
      cout << command << " " << ip << " "
           << "#" + a.find(ip)->second << endl;
    }
  }
}
