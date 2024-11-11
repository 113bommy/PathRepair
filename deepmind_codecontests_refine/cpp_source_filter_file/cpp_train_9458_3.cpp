#include<bits/stdc++.h>
#include<string>
using namespace std;
string divide[4]={"dream","erase","eraser","dreamer"};
string s;
bool DFS(int n){
    if(n==s.size())return true;
    for(string i:divide){
        if(n+i.size()<=s.size()&& s.sbustr(n,i.size())==i){
            if(DFS(n+i.size()))return true;
        }
    }
    return false;
}
int main(){
    cin>>s;
    cout<<DFS(0) ? "YES" :"NO")<<endl;
}