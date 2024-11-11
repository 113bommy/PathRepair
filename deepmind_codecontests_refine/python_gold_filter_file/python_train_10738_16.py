n,z = list(map(int, input().split()))
X = list(map(int, input().split()))
X.sort()

l = (n) // 2 - 1
r = n-1
m = (l+r) // 2
cnt = 0
for i in range(l, -1, -1):
    if X[r] - X[l] >= z:
        cnt += 1
        l -= 1
        r -= 1
    else:
        l -= 1

print(cnt)
