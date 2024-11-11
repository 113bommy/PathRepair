#include <bits/stdc++.h>
using namespace std;
1
int main(){
int X;
cin >>X;
vector <bool > expo(X+1);
expo[1] = 1;
for(int b=2;b<=X;b++){
int v = b*b;
while(v<=X){
expo[v] = 1;
v *= b;
}
}
for(int i=X;i>=1;i--) if(expo[i]){
cout <<i<<endl;
return 0;
}
}