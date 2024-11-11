L, R = map(int, input().split())
R = min(R, L+4038)
ans = 2018
for i in range(L, R):
    for j in range(i+1, R+1):
        ans = min((i*j)%2019, ans)
print(ans)
