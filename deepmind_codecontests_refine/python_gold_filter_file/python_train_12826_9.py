from collections import defaultdict
def ask_k(a, i):
    b = a[:]
    b.remove(a[i])
    print('?', end=' ')
    for j in range(k):
        print(b[j], end=' ')
    print()

n, k = map(int, input().split())
a = [i for i in range(1, n+1)]
d = defaultdict(int)
for i in range(k+1):
    ask_k(a, i)
    pos, val = map(int, input().split())
    d[val] += 1
mx = max(d)
print('!', d[mx])