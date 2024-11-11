L,R = map(int, input().split())
R = min(R, L+2019)
ans = 2018
for i in range(L,R+1):
    for j in range(i+1,R+1):
        x = (i*j)%2019
        ans = min(ans,x)
print(ans)