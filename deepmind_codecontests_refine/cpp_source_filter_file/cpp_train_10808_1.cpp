#include <bits/stdc++.h>
 
using namespace std;

int main(){
   int A,B,C,D;
   cin>>A>>B>>C>>D;
   i(abs(C-A)<=D)cout <<"Yes";
   else if(abs(B-A)<=D&&abs(C-B)<=D) cout <<"Yes";
   else cout <<"No";
 }

