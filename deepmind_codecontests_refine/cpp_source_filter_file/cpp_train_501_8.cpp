#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++){
  cin>>a.at(i);
  }
sort(a.begin(),a.end());
cout<<a(n-1)-a(0)<<endl;
return 0;
}
 