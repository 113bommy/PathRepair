from collections import Counter
N = int(input())
S = list(input())

c = Counter(S)

ans = 1
for cc in c.values():
    ans = (ans*(cc+1))%(10**9+7)
print(ans-1)