#include<bits/stdc++.h>

using namespace std;

int main(){
  long a,b,k;
  cin >> a >> b >> k;
  cout << max(0L,a-k) << " " << min(b,max(0L,a+b-k)) << endl;
}
