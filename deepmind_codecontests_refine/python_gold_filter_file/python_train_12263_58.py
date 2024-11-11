N = int(input())
ans = ":("
for i in range(N+1):
    if int(i*1.08) == N:
        ans = i
print(ans)