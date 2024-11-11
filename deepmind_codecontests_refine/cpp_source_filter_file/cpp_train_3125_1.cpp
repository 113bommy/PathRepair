#include<iostream>
using namespace std;
int main()
{
int n,a[100],ans=0;
cin >> n;
for(int i=0;i<n;i++)cin >> a[i];
for(int i=0;i<n;i++){
for(int j=n-1;j>=i+1;j--){
if(a[j]<a[j-1]){swap(a[j],a[j-1]);
}
}
for(int i=0;i<n;i++){
if(i==n-1)cout << a[i] << "\n";
else cout << a[i] << " ";
}
cout << ans << "\n";
return 0;
}