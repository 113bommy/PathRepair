from collections import defaultdict
N, K = map(int,input().split())
A = list(map(int,input().split()))
D = defaultdict(int)
for a in A:
  D[a]+=1
D = sorted(D.values())
ans = 0
if len(D)<=K:
  print(ans)
else:
    print(sum(D[:len(D)-K]))