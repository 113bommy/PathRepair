#include<iostream>
using namespace std;
int main(){
int n;

while(cin>>n){
long long pro = 1;
for(int i=1;i<=n;i++){
pro*=i;
}
cout << pro << endl;
}
return 0;
}