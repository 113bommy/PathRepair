#include "bits/stdc++.h"
#define ll long long
using namespace std;



int main(){
vector<pair<int,int>> tas;
ll n,tmp1,tmp2;
cin>>n;
for(int i=0;i<n;i++){
cin>>tmp1>>tmp2;
tas.emplace_back(make_pair(tmp2,tmp1));
}

sort(tas.begin(),tas.end());

int t=0;
for(int i=0;i<n;i++){
t+=tas[i].second;
if(tas[i].first<t){

        printf("No\n");
        return 0;
}
}



printf("Yes\n");

}
