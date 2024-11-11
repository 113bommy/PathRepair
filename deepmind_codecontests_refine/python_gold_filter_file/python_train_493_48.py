N = int(input())
ans = 0
for i in range(1,N):
    x = (N-1)//i
    ans += x
print(ans)