#include<iostream>]
#include<algorithm>
#include<vector>
using namespace std;
int main(){vector<int> a(10);int i=0;for(;i++<10;)cin>>a[i];sort(a.begin(),a.end());cout<<a[9]<<"\n"<<a[8]<<"\n"<<a[7]<<endl;}