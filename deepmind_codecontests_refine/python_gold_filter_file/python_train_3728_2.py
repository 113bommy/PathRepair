X, Y, Z, K = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))
AB = []
ans = []
for a in A:
    for b in B:
        AB.append(a + b)
AB.sort(reverse=True)
AB = AB[:min(3001, X*Y*Z+1)]
for c in C:
    for ab in AB:
        ans.append(c + ab)
ans.sort(reverse=True)
for i in range(K):
    print(ans[i])
