#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  bool ans=false;
  for(int i=0;i<n;i++){
    long long l;
    cin>>l;
      if(l%2==1)ans=true;
  }
  if(ans)cout<<"first"<<endl;
  else cout<<"second"<<endl;
}
