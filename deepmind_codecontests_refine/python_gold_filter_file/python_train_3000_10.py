def inpl(): return list(map(int, input().split()))

N, M = inpl()
A = inpl()
A.sort(reverse = True)

inf = float('inf')
match = (inf, 2, 5, 5, 4, 5, 6, 3, 7, 6)
matnum = set([match[a] for a in A])
dp = [0]+[-inf]*N

for i in range(1, N+1):
    dp[i] = max([10*dp[max(-1,i-match[a])] + a for a in A])

print(''.join(sorted(str(dp[-1]), reverse = True)))
