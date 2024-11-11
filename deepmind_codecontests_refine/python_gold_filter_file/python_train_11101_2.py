n = int(input())

c = [0,1]
p = [1]
for i in range(1, n):
    nc = [0] + c
    rev=False
    for j in range(len(p)):
        nc[j] -= p[j]
        if abs(nc[j]) > 1:
            rev = True
    if rev:
        for j in range(len(p)):
            nc[j] += 2*p[j]
            if abs(nc[j]) > 1:
                rev = True
        
    p = c
    c = nc
print(len(c)-1)
print(' '.join([str(i) for i in c]))
print(len(p)-1)
print(' '.join([str(i) for i in p]))