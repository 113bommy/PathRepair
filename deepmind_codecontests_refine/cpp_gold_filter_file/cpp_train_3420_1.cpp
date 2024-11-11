#include <vector>
#include <string.h>
#include<iostream>
#include<set>
#include<map>
#include<unordered_map>
#include<string.h>
#include<algorithm>
#include <stdlib.h>
#include<queue>
using namespace std;




int main(){
    int n;
    int before=0,after=0, ambiguous=0;
    cin>>n;
    vector<string>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    string name;
    cin>>name;
    priority_queue<int>str_has_q;
    for(int i=0;i<n;i++){
        string s,s2;
        s=vec[i],s2=vec[i];
        s2=s;
        bool q=false;
        for(int j=0;j<s.length();j++){
            if(s[j]=='?'){
                s[j]='a';
                s2[j]='z';
                q=true;
            }
        }
        if(q){
            if(s<name&&s2<name){
                before++;
            } else if(s>name&&s2>name){
                after++;
            } else {
                ambiguous++;
            }
            str_has_q.push(i);
        }
    }
    
    while(str_has_q.size()){
        int to=str_has_q.top();
        str_has_q.pop();
        vec.erase(vec.begin()+to);
    }
    sort(vec.begin(),vec.end());
    bool out=false;
    if(vec[0]>name){
        for(int i=max(0,before-after);i<before;i++)
            cout<<1+i<<" ";
        cout<<1+before<<endl;
        return 0;
    }
    vector<int>ans;
    for(int i=0;i<vec.size();i++){
        if(name==vec[i]){
            ans.push_back(i+1);
            out=true;
        }
        if(i>0&&vec[i]>name&&name>=vec[i-1]){
            ans.push_back(i+1);
            
            set<int>ind;
            for(int i=0;i<=ambiguous;i++){
                for(auto a:ans){
                    ind.insert(before+i+a);
                }
            }
            vector<int>ult;
            for(auto a:ind){
                ult.push_back(a);
            }
            for(int i=0;i<ult.size()-1;i++){
                cout<<ult[i]<<" ";
            }
            cout<<ult[ult.size()-1]<<endl;
            return 0;
        }
    }
    ans.push_back(vec.size()+1);
    set<int>ind;
    for(int i=0;i<=ambiguous;i++){
        for(auto a:ans){
            ind.insert(before+i+a);
        }
    }
    vector<int>ult;
    for(auto a:ind){
        ult.push_back(a);
    }
    for(int i=0;i<ult.size()-1;i++){
        cout<<ult[i]<<" ";
    }
    cout<<ult[ult.size()-1]<<endl;
    //else cout<<endl;
    return 0;
}