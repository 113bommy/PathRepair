n, k = [int(i) for i in input().split()]
m = sorted([[int(i) for i in input().split()] for _ in range(n)])

s=0
i=0
while s<k:
    s += m[i][1]
    i += 1
print(m[i-1][0])
