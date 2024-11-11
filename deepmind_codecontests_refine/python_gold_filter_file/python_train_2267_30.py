X, N = map(int, input().split())
p = list(map(int, input().split()))
ans = 102
for i in range(-100,102):
    if not i in p:
        if abs(i-X) < abs(ans-X):
            ans = i

print(ans)
    