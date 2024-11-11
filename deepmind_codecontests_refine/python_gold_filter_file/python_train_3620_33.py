from collections import defaultdict
from bisect import *

def into_dict(dics,x,y,u):
  x,y = int(x),int(y)
  insort(dics[u+'_x'][x],y)
  insort(dics[u+'_y'][y],x)
  insort(dics[u+'_xpy'][x+y],x)
  insort(dics[u+'_ymx'][y-x],x)
  return dics

def para(dics,dic1,dic2):
  ans = float('inf')
  for k,v in dics[dic1].items():
    for zahyou in v[1:-1]:
      ind = bisect_right(dics[dic2][k],zahyou)
      dis = zahyou-dics[dic2][k][ind-1]
      ans = min(ans,dis)
  return ans

def solve():
  ans = []
  N = int(input())
  dics = defaultdict(lambda: defaultdict(lambda: [-float('inf'),float('inf')]))
  for i in range(N):
    dics = into_dict(dics,*input().split())
  lis1 = [['L_y','R_y'],['D_x','U_x']]
  lis2 = [['L_ymx','U_ymx'],['U_xpy','R_xpy'],['L_xpy','D_xpy'],['D_ymx','R_ymx']]
  for arg in lis1:
    ans.append(para(dics,*arg)*5)
  for arg in lis2:
    ans.append(para(dics,*arg)*10)
  ans = min(ans)
  return ans if ans<float('inf') else 'SAFE'
print(solve())