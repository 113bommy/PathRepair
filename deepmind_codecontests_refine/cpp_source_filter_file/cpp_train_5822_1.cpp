#include <bits/stdc++.h>
using namespace std;

int main(void){
    int M,T,P,R,m,t,p,j;

    while(cin>>M>>T>>P>>R, M|T|P|R){
        int cnt[51]={};
        int time[51]={};
        int penalty[51][11]={};
        int s[51]={};

        /*????????¨??????????????£????¨????*/
        while(R--){
            cin>>m>>t>>p>>j;
            if(j==0){
                ++cnt[t];
                time[t] += m+penalty[t][p];
            }
            else penalty[t][p]+=20;
        }

        /*???????????¨??????*/
        for(t=1;t<=T;t++)s[t]=t;

        /*??????????????????*/
        for(int a=1;a<T;a++){
            for(int b=T;b>a;b--){
                if(cnt[s[b]]<cnt[s[b-1]]
                   ||(cnt[s[b]]==cnt[s[b-1]] && time[s[b]]>time[s[b-1]])
                   ||(cnt[s[b]]==cnt[s[b-1]] && time[s[b]]==time[s[b-1]] && s[b]<s[b-1]))
                    swap(&s[b],&s[b-1]);
            }
        }

        /*??????????????????????????????*/
        for(t=T;t>=1;t--){
            cout<<s[t];
            if(t==1)break;
            if(cnt[s[t]]==cnt[s[t-1]] && time[s[t]]==time[s[t-1]])cout<<"=";
            else cout<<",";
        }
        cout<<endl;

    }
    return 0;
}