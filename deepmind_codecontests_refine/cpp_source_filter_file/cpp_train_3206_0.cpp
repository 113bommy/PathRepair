#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a, b, k;
  cin >> a >> b >> k;
  cout << max((a-k),0) << " " << min(b,max((a+b-k),0)) << endl;
}