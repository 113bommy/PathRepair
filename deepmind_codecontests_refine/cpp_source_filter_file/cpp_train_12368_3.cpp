#include <bits/stdc++.h>
using namespace std;
 
double main() {
 double w,h,x,y;
  cin>>w>>h>>x>>y;
  int m=0;
  if (x==w/2 && y==h/2){
    m=1;}
  
  cout<<w*h/2<<' '<<m<<endl;
}