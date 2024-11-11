# Forbidden List
X,N = map(int,input().split())
p = list(map(int, input().split()))
ans = 200
for i in range(-1,102):
    if i not in p:
        ans = [ans, i][abs(X-i) < abs(X-ans)]
print(ans)