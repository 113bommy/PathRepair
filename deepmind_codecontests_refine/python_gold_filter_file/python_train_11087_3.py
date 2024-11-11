from sys import stdin

n = int(stdin.readline())
hi = list(map(int, stdin.readline().split()))

res = [''] * n

vmax = 0

for i in range(n - 1, -1, -1):
    if vmax < hi[i]:
        vmax = hi[i]
        res[i] = '0'
    else:
        res[i] = str(vmax - hi[i] + 1)
        
print(" ".join(res))