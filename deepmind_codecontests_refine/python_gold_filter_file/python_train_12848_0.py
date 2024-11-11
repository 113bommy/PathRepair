import itertools

N = int(input())
L = [int(x) for x in input().split()]
M = list(sorted(enumerate(L), key = lambda x: x[1]))
code = [0 for x in L]
last = 0
last_key = 0
for k, group in itertools.groupby(M, key = lambda x:x[1]):
    last <<= k - last_key
    last_key = k
    for g in group:
        s = bin(last)[2:]
        code[g[0]] = '0'*(k - len(s)) + s
        last += 1
    if last >= (1 << k) + 1:
        print('NO')
        break
else:
    print('YES')
    for i in range(N):
        print(code[i])
    
