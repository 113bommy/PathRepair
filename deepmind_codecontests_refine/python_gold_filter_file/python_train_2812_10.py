n = int(input())
S = set(map(int, input().split()))
q = int(input())
T = list(map(int, input().split()))
ans = 0
for t in T:
    if t in S:
        ans += 1
print(ans)
