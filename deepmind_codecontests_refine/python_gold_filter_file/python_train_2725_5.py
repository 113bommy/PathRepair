import sys
input = sys.stdin.readline

Q = int(input())
Query = []
for _ in range(Q):
    N = int(input())
    S = list(input().rstrip())
    Query.append((N, S))

for N, S in Query:
    ans = []
    for start in range(10):
        last = start
        last1 = -1
        T = []
        for i, s in enumerate(S):
            n = int(s)
            if n >= last:
                T.append("2")
                last = n
            elif n >= last1:
                T.append("1")
                last1 = n
            else:
                T = []
                break
        if T and last1 <= start:
            ans = T
    if not ans:
        print("-")
    else:
        print("".join(ans))