#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  string s;
  while(getline(cin,s)){
    s+=' ';
    stack<double>st;
    double p=0;
    int t=0;
    r(i,s.size()){
      if(s[i]==' '&&isdigit(s[i-1])){
        if(p!=0){
          if(!t)st.push(p),p=0;
          else st.push((-1)*p),p=0,t=0;
        }
      }
      else if(s[i]=='*'){
        double x1=st.top();st.pop();
        double x2=st.top();st.pop();
        st.push(x2*x1);
      }
      else if(s[i]=='+'){
        double x1=st.top();st.pop();
        double x2=st.top();st.pop();
        st.push(x2+x1);
      }
      else if(s[i]=='/'){
        double x1=st.top();st.pop();
        double x2=st.top();st.pop();
        st.push(x2/x1);
      }
      else if(s[i]=='-'){
        if(isdigit(s[i+1]))t++;
        else{
          double x1=st.top();st.pop();
          double x2=st.top();st.pop();
          st.push(x2-x1);
        }
      }
      else if(isdigit(s[i])){
        p*=10,p+=s[i]-'0';
      } 
    }
    printf("%.6f\n",st.top());
  }
}
}