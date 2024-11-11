#include<bits/stdc++.h>
using namespace std;
const int uchiha=1e3+5;
int main(){
set<int,int> st;
int n,x;
cin>>n;
while(n--){
    cin>>x;
    st.insert(x);
}
cout<<st.size();
}
