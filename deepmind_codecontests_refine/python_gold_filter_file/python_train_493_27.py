N = int(input())
ans = 0
for a in range(1, N+1):
    ans += (N-1)//a
print(ans)
