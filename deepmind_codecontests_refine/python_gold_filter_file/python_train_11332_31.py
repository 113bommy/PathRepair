from itertools import product as prd

n, m = map(int, input().split())
a = [input() for i in range(n)]
b = [input() for i in range(m)]


c = n - m + 1
ans = [list(map(lambda l: l[j:j+m], a[i:i+m])) == b for i, j in prd(range(c), range(c))]
print("Yes" if any(ans) else "No")
