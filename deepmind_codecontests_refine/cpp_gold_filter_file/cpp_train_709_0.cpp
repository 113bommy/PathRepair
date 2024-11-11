#include <iostream>
using namespace std;

int main(){
int n,a[100005];
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];

int two=0,four=0,no=0;
for(int i=0;i<n;i++){
if(a[i]%4==0)four++;
else if(a[i]%2==0)two++;
else no++;
}
no+=two%2;
if(four>=no-1) cout << "Yes" <<endl;
else cout << "No"<<endl;
}
