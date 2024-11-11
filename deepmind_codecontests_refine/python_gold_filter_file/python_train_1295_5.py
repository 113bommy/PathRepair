s, l = map(int, input().split())

b = list([int(x) for x in bin(min(s,l))[2:]])

i = 0
ans = []
while s > 0 and i < len(b):
    k = len(b) - i - 1
    a = 2**(len(b) -1 - k)
    n = 2**k
    while n <= l and s >= 2**k  and a > 0:
        s -= 2**k
        a -= 1
        ans.append(str(n))
        n += 2**(k+1)
    i += 1

if s != 0:
    print(-1)
else:
    print(len(ans))
    print(' '.join(ans))
