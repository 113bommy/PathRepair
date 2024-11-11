#include<iostream>
#indlude<vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x - 1;
  }
  for (int x : a) cout << x << " ";
}