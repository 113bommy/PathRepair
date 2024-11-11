#include <bits/stdc++.h>
using namespace std;
vector<int> v1;
vector<int> v2;
vector<int> v3;
vector<int> num;
int n, index2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    num.push_back(b);
  }
  for (int i = 0; i < n; i++) {
    if (num[i] < 0) v1.push_back(num[i]);
    if (num[i] == 0) v3.push_back(0);
    if (num[i] > 0) v2.push_back(num[i]);
  }
  if (v2.size() == 0) {
    v2.push_back(v1[v1.size() - 1]);
    v2.push_back(v1[v1.size() - 2]);
    v1.erase(v1.begin() + v1.size() - 1);
    v1.erase(v1.begin() + v1.size() - 1);
  }
  if (v1.size() % 2 == 0) {
    v3.push_back(v1[v1.size() - 1]);
    v1.erase(v1.begin() + v1.size() - 1);
  }
  cout << v1.size() << " ";
  for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
  cout << "\n" << v2.size() << " ";
  for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
  cout << "\n" << v3.size() << " ";
  for (int i = 0; i < v3.size(); i++) cout << v3[i] << " ";
}
