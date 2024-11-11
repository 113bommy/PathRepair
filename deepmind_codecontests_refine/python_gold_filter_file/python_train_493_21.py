n = int(input())
ans=0
for i in range(1,n):
    ans+=int((n-1)/i)
print(ans)