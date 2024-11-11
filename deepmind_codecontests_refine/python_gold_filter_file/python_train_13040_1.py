test=int(input())
for cases in range(test):
 n=int(input())
 als=list(map(int,input().split()))
 bls=list(map(int,input().split()))
 amin=sorted(als)[0]
 bmin=sorted(bls)[0]
 ans=0
 for i in range(n):
  ans+=max(als[i]-amin,bls[i]-bmin)
 print(ans)