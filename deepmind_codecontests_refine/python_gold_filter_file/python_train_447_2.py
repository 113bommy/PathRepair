n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
k = 0
for i in range(n):
    s2 = sum(a[i])
    for j in range(n):
        s1 = sum(a[ii][j] for ii in range(n))
        if s1 > s2:
            k += 1
print(k)
