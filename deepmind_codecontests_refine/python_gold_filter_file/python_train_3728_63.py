X, Y, X, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
A.sort(reverse=True)
B.sort(reverse=True)
C.sort(reverse=True)

ab = [a+b for a in A for b in B]
ab.sort(reverse=True)

ans = [x+c for x in ab[:K] for c in C]
ans.sort(reverse=True)
print('\n'.join(map(str, ans[:K])))
