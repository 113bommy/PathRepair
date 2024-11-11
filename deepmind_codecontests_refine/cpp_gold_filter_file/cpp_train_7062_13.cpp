# include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
if(((n%1000)/100)==n%10){
    cout<<"Yes";
}
else {
    cout<<"No";
}
}
