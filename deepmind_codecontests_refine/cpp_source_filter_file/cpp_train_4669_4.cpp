#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int N,i,a,b;
vector<int> A,B;
cin>>N;
for(i=0;i<N;i++){
cin>>a>>b;
A.push_back(a);
B.push_back(b);
}
sort(A.begin(), A.end());
sort(B.begin(), B.end());
cout<<b[0]+A[N-1];
return 0;
}