#include<bits/stdc++.h>
using namespace std;

int main(){

for(;;){
strin num;
cin>>num;
if(num=="0"){break;}
int al={};

for(int i=0;i<(int)num.size();i++){
al+=num[i]-'0';
}

cout<<al<<endl;
}

return 0;
}
