#include<iostream>
#include<algorithm>

using namespace std;
int x[10];
int main(){
for(int i=0;i<10;i++){
cin>>x[i];
}
sort(x,x+10);
cout<<x[9]<<endl;
cout<<x[8]<<endl;
cout<<x[7]<<endl;
return 0;
}