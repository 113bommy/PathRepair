N,A,B=map(int,input().split())
if (B+A)%2==0:
    ans=(B-A)//2
else:
    ans=min(A-1,N-B)+1+(B-A-1)//2
print(ans)