N = int(input())
a = sorted(list(map(int, input().split())), reverse=True)

ans = 0

for i in range(N-1):
    ans += a[(i+1)//2]
print(ans)
