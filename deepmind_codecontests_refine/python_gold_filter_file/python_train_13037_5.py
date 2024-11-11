import io,os
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
import sys
from collections import defaultdict
def solve(n,A):
    if n==1:
        return 1
    if n==2:
        if len(set(A))==1:
            return 2
        return 1
    L=[[0]*27 for _ in range(n+1)]
    for i,a in enumerate(A):
        for j in range(27):
            L[i+1][j]=L[i][j]
        L[i+1][a]+=1
    ans=0
    for l in range(n):
        for r in range(l,n):
            Left,Right=[0]*27,[0]*27
            mid=0
            for i in range(27):
                Left[i]=L[l][i]
                mid=max(mid,L[r+1][i]-L[l][i])
                Right[i]=L[n][i]-L[r+1][i]
            tmp=0
            for i in range(27):
                tmp=max(tmp,min(Left[i],Right[i]))
            #print(l,r,tmp,mid)
            ans=max(ans,mid+tmp*2)
    return ans

def main():
    t=int(input())
    for _ in range(t):
        n=int(input())
        A=tuple(map(int,input().split()))
        ans=solve(n,A)
        sys.stdout.write(str(ans)+'\n')
    
if __name__=='__main__':
    main()