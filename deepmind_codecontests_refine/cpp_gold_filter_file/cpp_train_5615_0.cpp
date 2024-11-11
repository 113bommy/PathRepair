#include<bits/stdc++.h>
using namespace std;

int getNum(char c){
  if('A'<=c&&c<='Z')return 10+c-'A';
  if('a'<=c&&c<='z')return 36+c-'a';
  return c-'0';
}

int pto10(int p,string s){
  int res=0,x=1;
  for(int i=0;i<s.size();i++)res+=x*getNum(s[i]),x*=p;
  return res;
}

int Cnt(int num){
  int res=0;
  while(num)res++,num/=2;
  return res;
}

int main(){
  int n,p,cnt1=0,cnt2=0;
  vector<int> v;
  string s;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>p>>s;
    reverse(s.begin(),s.end());
    int num=pto10(p,s),t=0;
    while(num){
      if(num%2)t=t*10+1;
      else v.push_back(t),t=0;
      num/=2;
    }
    v.push_back(t);
  }
  for(int i=0;i<v.size();i++){
    int cnt=Cnt(v[i]);
    if(!v[i])continue;
    if(cnt==1)cnt1++;
    else cnt2++;
  }
  if(cnt2||cnt1%2)cout<<"win"<<endl;
  else cout<<"lose"<<endl;
  return 0;
}