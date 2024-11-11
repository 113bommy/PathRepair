#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
long long b, c, n, m, x, cnt;
string s, o, name = "shohrukh";
vector<int> v;
vector<int> ve;
pair<int, int> p;
int main() {
  int a, b;
  cin >> a >> b;
  int arr[a][a];
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      arr[i][j] = 0;
    }
  }
  for (int i = 0; i < a; i++) {
    arr[i][i] = b;
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
