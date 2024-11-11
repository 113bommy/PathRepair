import bisect
n=int(input())
L=[int(x) for x in input().split()]
L.sort()
ans=0

for i in range(n):
  for j in range(i+1,n):
    k=bisect.bisect_left(L, L[i]+L[j])-j-1
    ans+=k
    
    
print(ans)