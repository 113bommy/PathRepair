#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  if (n % 2 == 0 && substr(0, n/2) == substr(n/2, n/2)) {
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
}