n, m = list(map(int,input().split()))
ans = min(n,m) + 1
print(ans)
for i in range(ans):
    print(i,min(n,m)-i)