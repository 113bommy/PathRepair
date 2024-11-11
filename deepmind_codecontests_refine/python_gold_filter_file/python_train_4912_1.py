R = lambda: map(int, input().split())
n = int(input())
L = sorted(R())
d = {}
f = [0]*101
for i in L:f[i] = 1
res = 0
for i in range(1,101):
    if f[i] == 1:
        res += 1
        for j in L:
            if j % i == 0 and f[j] == 1:
                f[j] = 0
print(res)