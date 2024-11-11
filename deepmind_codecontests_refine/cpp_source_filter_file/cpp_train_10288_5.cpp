#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  
 int a;
cin >>a;
  
long long int x[110],y[110],h[110];

  
for (int i=0;i<a;i++){
cin >>x[i] >>y[i] >> h[i];
}
for (int posx=0;posx<=100;posx++){
  
      for (posy=0;posy<=100;posy++){
            for ( int nh=(h[0]-100);nh<=h[0]+100;nh++){
              
    bool abcd=true;
              
         for ( int i=0;i<a;i++){
           
long long int k=0;
if(h[i]!=max(nh-abs(posx-x[i])-abs(posy-y[i]),k)) abcd=false;
}
if (abcd==true) 
  cout <<posx <<" "<< posy <<" "<<nh <<endl;
           }
      }
}
}
