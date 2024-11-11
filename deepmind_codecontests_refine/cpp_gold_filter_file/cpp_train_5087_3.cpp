#include <bits/stdc++.h>

using namespace std;

int main(){
 int n; 
  cin >>  n;
  
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
   cin >> a[i];
  }
  
  int res=0;
  for(int i=1;i<=n;i++){
   if(a[a[i]]==i) res++;
  }
   cout << res/2 << endl;
}
