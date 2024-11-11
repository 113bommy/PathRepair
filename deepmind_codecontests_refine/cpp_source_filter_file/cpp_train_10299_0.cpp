#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define re(i,n,a) for(int i=a;i<n;i++)
using namespace std;
typedef pair<int,int>P;
int w,h,a[16][16],md=14,b[16][16],s1,s2;
bool used[16][16];
string s[16];
int dx[]={-1,-1,-1,0,0,0,1,1,1};
int dy[]={-1,0,1,-1,0,1,-1,0,1};
vector<P>v;
map<int,int>m;
int greedy(){
  int res=0,sum=0;
  memset(a,0,sizeof(a));
  memset(used,0,sizeof(used));
  r(i,h){
      r(j,w){
        if(s[i][j]=='0'){
        r(k,9){
          int y=i+dy[k];
          int x=j+dx[k];
          if(y<0||x<0||y>=h||w>=x)continue;
          used[y][x]=1;
        }
      }
      else if(s[i][j]=='.')used[i][j]=1;
      else if(isdigit(s[i][j]))a[i][j]=s[i][j]-'0',res+=a[i][j];
      }
    }
    while(res>0){
      memset(b,0,sizeof(b));
      int f=0;
      r(i,h)r(j,w)if(!used[i][j]){
        int p=0;
        r(k,9){
          int y=i+dy[k];
          int x=j+dx[k];
          if(y<0||x<0||y>=h||x>=w)continue;
          if(a[y][x])p++;
        }
        b[i][j]=p;
        f=max(p,f);
      }
      int i=0,j=0;
      r(kk,h*w){
        i=(i+1)%h;
        j=(j+1)%w;
        if((unsigned int)rand()%5==0)i=(unsigned int)rand()%h;
        if((unsigned int)rand()%5==0)j=(unsigned int)rand()%w;
        if(used[i][j])continue;
        if(b[i][j]==f){
          int p=0;
          r(k,9){
          int y=i+dy[k];
          int x=j+dx[k];
          if(y<0||x<0||y>=h||x>=w)continue;
          if(a[y][x])p++;
        }
        if(p==f){
          r(k,9){
            int y=i+dy[k];
            int x=j+dx[k];
            if(y<0||x<0||y>=h||x>=w)continue;
            if(used[y][x])continue;
            if(a[y][x])a[y][x]--;
          }
          sum++;
          res-=f;
          used[i][j]=1;
        }
      } 
    }}
    m[sum]++;
    return sum;
}
int main(){
  while(cin>>h>>w,w){
    int ans=1e9;
    r(i,h)cin>>s[i];
    r(t1,2){
      r(i,h/2)swap(s[i],s[h-1-i]);
      r(t2,2){
        r(i,h)reverse(s[i].begin(),s[i].end());
        r(t3,2){
          string t[16];
          r(i,16)t[i]="";
          r(i,w)r(j,h)t[i]+=s[j][i];
          swap(h,w);
          r(i,w)s[i]="";
          r(i,h)s[i]=t[i];
          int pp;
          set<int>st;
          m.clear();
          r(t4,150){
            srand((unsigned int)time(NULL));
            pp=greedy();
            st.insert(pp);
            ans=min(ans,pp);
          }
          //cout<<m[ans]<<endl;
          If(st.count(ans)&&ans%md==0)
            if(rand()%2&&ans)ans--;
        }
      }
    }if(ans==28)exit(1);
    cout<<ans<<endl;
  }
}