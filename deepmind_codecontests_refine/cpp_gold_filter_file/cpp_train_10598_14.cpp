#include <iostream>
using namespace std;
int main() {
int r,x,D,l;
l=1;
cin>>r>>D>>x;
while(l<=10){
x=r*x-D;
cout<<x<<endl;
l++;
}
return 0;
}