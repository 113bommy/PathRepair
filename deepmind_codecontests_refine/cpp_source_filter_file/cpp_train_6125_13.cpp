#include <bits/stdc++.h>
using namespace std;
int main(){
int A,B,C,D;
cin>>A>>B>>C>>D;
if((A+B)>(C+D))cout<<"Left";
else((A+B)==(C+D))cout<<"Balanced";
else cout<<"Right";
return 0;
}
