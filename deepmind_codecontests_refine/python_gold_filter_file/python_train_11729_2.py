from collections import Counter

names = ["Kuro", "Shiro", "Katie"]

def solve(s, n):
    d = Counter(s)
    if len(d) == 1 and n == 1:
        return len(s) - 1
    m = max(d.values())
    return min(m+n,len(s))

n = int(input())
p = []
for _ in range(3):
    p.append(input())

l = sorted([ (solve(p[i],n),i) for i in range(len(p))])

if l[2][0] > l[1][0]:
    print(names[l[2][1]])
else:
    print("Draw")

