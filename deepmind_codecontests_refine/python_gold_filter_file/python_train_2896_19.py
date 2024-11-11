from itertools import accumulate
N, K = map(int, input().split())
As = list(map(int, input().split()))

subsecs = []
S = [0] + list(accumulate(As))
for f in range(1, N+1):
    for t in range(f, N+1):
        subsecs.append(S[t] - S[f-1])

ans = 0
digit = 1 << 40
for d in range(41):
    nsubsecs = []
    for subsec in subsecs:
        if subsec & digit:
            nsubsecs.append(subsec)
    if len(nsubsecs) >= K:
        ans += digit
        subsecs = nsubsecs
    digit >>= 1
print(ans)
