#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k;
    cin>>s;
    cin>>k;
    set<string> sub;
    for(int i=0;i<s.size();i++){
        for(int j=1;i+j-1<s.size()&&j<=k;j++){
            sub.insert(s.substr(i,j));
        }
    }
    
    auto itr=sub.begin();
    for(int i=0;i<k-1;i++){
        itr++;
    }
    cout<<*itr<<endl;
    
    return 0;
}
