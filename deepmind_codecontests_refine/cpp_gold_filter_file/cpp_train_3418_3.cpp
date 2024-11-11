#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,e,f,g,h,i;
  cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
  if(b-a==e-d&&e-d==h-g && c-b==f-e&&f-e==i-h && a-d==b-e&&b-e==c-f && d-g==e-h&&e-h==f-i)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
