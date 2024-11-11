A,B,C=[int(_) for _ in input().split()]
ans=2*min(A,B)+1+2*C
if A==B:
 ans-=1
print(ans)
