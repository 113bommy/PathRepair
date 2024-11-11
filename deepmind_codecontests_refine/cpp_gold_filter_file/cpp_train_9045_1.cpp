#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <string>

//typedef pair<int,int> P;

using namespace std;

const int INF=INT_MAX/3;
const int N=1000;

int heap[N];
string output;

void parse(string &s,int id){

  //cout<<s<<":"<<id<<endl;
  if(s.empty()) return;

  heap[id]++;
  if(s=="(,)") return;
  if(id>=N) return;
  
  int cnt=0;
 
  for(int i=1;i<s.length()-1;i++){
    if(s[i]=='(') cnt++;
    if(s[i]==')') cnt--;  
    if(s[i]==',' && cnt==0){
      string sub1=s.substr(1,i-1);
      string sub2=s.substr(i+1,s.length()-i-2);
      if(i-1>=0) parse(sub1, 2*id+1);
      if(s.length()-i-2>=0)parse(sub2, 2*id+2);
      break;
    }
  }
  return;
}

void out(int th, int id){

  output.push_back('(');

  int ch1=0,ch2=0;//n of string of each child
  
  if(heap[id]>th && heap[2*id+1]>th){
    out(th,2*id+1);
  }
  output.push_back(',');
  if(heap[id]>th && heap[2*id+2]>th){
    out(th,2*id+2);
  }
  
  output.push_back(')');
  return;
  
}

void print(){

  for(int i=0;i<N;i++)
    cout<<"["<<i<<"]"<<heap[i]<<endl;
}

void solve(string cmd,string &s1,string &s2){

  fill(heap,heap+N,0);
  output.clear();
  //cout<<output<<endl;
  parse(s1,0);
  parse(s2,0);


  int th=-1;
  if(cmd=="u") th=0;
  if(cmd=="i") th=1;
  out(th,0);
  
  cout<<output<<endl;
}



int main(){

  string cmd,s1,s2;
  int i=0;
  
  while(cin>>cmd>>s1>>s2){
    solve(cmd,s1,s2);
  }

  return 0;
}