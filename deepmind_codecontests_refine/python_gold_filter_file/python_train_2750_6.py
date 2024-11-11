n = int(input())
a = list(map(int, input().split()))

M=0
L=0
b = []
for i in range(0, 1001):
    if i in a:
        L += 1
        m = a.count(i)
        if (m > M):
            M = m
print (M, L)
