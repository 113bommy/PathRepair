N,K,S = map(int,input().split())
A = [S]*K
if S == 10**9:
    A.extend([1]*(N-K))
else:
    A.extend([10**9]*(N-K))
print(*A, sep = " ")