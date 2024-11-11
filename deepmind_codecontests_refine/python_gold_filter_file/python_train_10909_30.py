N = int(input())
S = input()
X = ["{:03d}".format(i) for i in range(1000)]
# print(X)
ans = 0
for x in X:
    now = 0
    for s in S:
        if s == x[now]:
            now += 1
        if now == 3:
            ans += 1
            break
print(ans)