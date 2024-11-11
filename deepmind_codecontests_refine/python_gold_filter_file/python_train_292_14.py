n = int(input())
p = list(map(int, input().split()))

cnt = 0
for i in range(n):
    if p[i] == i+1:
        if i+1 < n:
            p[i], p[i+1] = p[i+1], p[i]
        cnt += 1
print(cnt)
