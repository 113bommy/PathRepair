n = int(input())
*a, = map(int, input().split())
ans = [0] * n
for i in range(n-1, -1, -1):
    if not sum(ans[i::i+1]) % 2 == a[i]:
        ans[i] = 1
print(sum(ans))
print(*[i+1 for i in range(n) if ans[i] == 1])
