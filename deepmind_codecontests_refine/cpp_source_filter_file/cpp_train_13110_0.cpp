#include<iostream>
using namespace std;

int main(){
    int n;
    while(true){
        cin>>n;
        if(n==0){break;}
        int table[26]={0},max1=0,max2=0;
        char cha[n+1],m_cha[2];
        for(int i=0;i<n;i++)cin>>chara[i];
        for(int t=0;t<n;t++){
            table[cha[t]-'A']++;
            if(table[cha[t]-'A']>max1){
                max1=table[cha[t]-'A'];
                m_cha[0]=cha[t];
            }
            else if(table[cha[t]-'A']>max2)max2=table[cha[t]-'A'];
            if(max1-max2 >= n-t){
                cout<<m_cha[0]<<" "<<t+1<<endl;
                break;
            }
            if(t==n-1)
                if(max1==max2)
                    cout<<"TIE"<<endl;
        }
    }
}
