#include<iostream>

using namespace std;

int main(){
int a,b,c;
cin>>a>>b>>c;
if(b>=c){
cout<<"delicious"<<endl;
}
else if(a>=c-b)
cout<<"safe"<<endl;
else
cout<<"dangerous"<<endl;

return 0;
}