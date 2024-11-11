n=int(input())
d,x=map(int,input().split())
ans=x+n
for _ in range(n):
  ans+=(d-1)//int(input())
print(ans)