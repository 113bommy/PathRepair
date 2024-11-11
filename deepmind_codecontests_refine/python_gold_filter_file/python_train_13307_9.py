from collections import Counter
from itertools import combinations

n = int(input())
l = Counter(input()[0] for _ in range(n))
con = [l[c] for c in 'MARCH' if c in l]
print(sum(a * b * c for a, b, c in combinations(con, 3)))
