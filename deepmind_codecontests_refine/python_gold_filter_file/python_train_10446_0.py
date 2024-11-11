w,h=map(int,input().split())
ans=0
for i in range(2,w+1,2):
    for j in range(2,h+1,2):
        ans+=(w+1-i)*(h+1-j)
print(ans)