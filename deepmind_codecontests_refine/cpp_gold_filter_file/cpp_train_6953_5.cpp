#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n;cin >> n;
  string S="No";
  for (int i=1;i<10;i++) {
    for (int j=1;j<10;j++) {if (i*j==n) S="Yes";}
  }
  cout << S << endl;
}
