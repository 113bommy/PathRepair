import collections
N,K = map(int,input().split())
A = list(map(int,input().split()))
c = collections.Counter(A).most_common()[::-1]
k = len(c)
if k<=K:print(0)
else: print(sum([e[1] for e in c[:k-K]]))