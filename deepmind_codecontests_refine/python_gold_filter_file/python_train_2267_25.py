X, N = map(int, input().split())
p = list(map(int, input().split()))
 
ans = 0
for i in range(1, 102):
    if abs(X - i) < abs(X - ans) and i not in p:
        ans = i
print(ans)