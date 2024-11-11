N = int(input())
P = list(map(int, input().split()))

ans = 0

for i in range(N):
    ans += P[i] != i+1

print('NO' if ans > 2 else 'YES')