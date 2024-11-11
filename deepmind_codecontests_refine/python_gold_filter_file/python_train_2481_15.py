n=int(input())
d,x=map(int,input().split())
ans=n
for i in range(n):
    ans+=(d-1)//int(input())
print(ans+x)
