#include <bits/stdc++.h>
using namespace std;

int main() {
  long long h, w;
  cin >> h >> w;
  
  if(h!=1 && w!=1) cout << (h*w+1)/2 << endl;
  else cout<<1<<endl;
}
