#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

struct Side{
  int h,w,ul,ur,dl,dr; // h:上端からの距離 w:縦棒aとa+1をむずぶ
  // ul:左上にたどった時の縦棒 ur:右上にたどった時の縦棒 dl:左下へたどった時の縦棒 dr:右下へたどった時の縦棒
  Side(int h=0, int w=0, int ul=-1, int ur=-1, int dl=-1, int dr=-1):h(h),w(w),ul(ul),ur(ur),dl(dl),dr(dr){}
  bool operator<(const Side &a)const{ return h < a.h; }
};

const int INF = 1<<30;

int N,M,H,K;
Side ss[100005];
int s[1024], l[1024];
map<int, int>m;

int main(){
  while(scanf("%d%d%d%d", &N,&M,&H,&K) && N||M||H||K){
    m.clear();
    for(int i=0;i<N;i++) scanf("%d", &s[i]);
    for(int i=0;i<M;i++){
      int a,b;
      scanf("%d%d", &a,&b); a--;
      ss[i] = Side(b,a);
    }
    for(int i=0;i<N;i++) l[i] = i;
    sort(ss, ss+M);
    for(int i=0;i<M;i++){
      Side &sd = ss[i];
      sd.ul = l[sd.w]; sd.ur = l[sd.w+1];
      swap(l[sd.w], l[sd.w+1]);
      sd.dl = l[sd.w]; sd.dr = l[sd.w+1];
    }
    for(int i=0;i<N;i++) m[l[i]] = i;
    for(int i=0;i<M;i++){
      Side &sd = ss[i];
      sd.dl = m[sd.dl]; sd.dr = m[sd.dr];
      //      printf("%d %d %d %d %d %d\n", sd.h, sd.w, sd.ul, sd.ur, sd.dl, sd.dr);
    }
    //    for(int i=0;i<N;i++) printf("%d ", l[i]); puts("");
    int sum = 0;
    for(int i=0;i<K;i++) sum += s[m[i]];
    int res = sum;
    //    printf("%d\n", res);
    for(int i=0;i<M;i++){
      Side sd = ss[i];
      int diff = 0;
      int l=0, r=0;
      if(0 <= sd.ul && sd.ul < K) l = 1;
      if(0 <= sd.ur && sd.ur < K) r = 1;
      if(!l && r) diff = s[sd.dr] - s[sd.dl];
      else if(l && !r) diff = s[sd.dl] - s[sd.dr];
      //      printf("%d %d %d\n", l, r, diff);
      //      printf("%d\n", sum + diff);
      res = min(res, sum + diff);
    }
    printf("%d\n", res);
  }
  return 0;
}