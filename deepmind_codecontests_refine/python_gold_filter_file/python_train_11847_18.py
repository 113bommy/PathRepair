N,A,B=map(int,input().split())
if (A-B)%2==0:
  ans=int((B-A)//2)
else:
  ans=int(min(A-1,N-B)+1+(B-A-1)//2)
print(ans)