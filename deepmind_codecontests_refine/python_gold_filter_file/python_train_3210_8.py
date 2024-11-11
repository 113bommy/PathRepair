A, B, K = map(int, input().split())
r = range(A, B+1)

for s in sorted(set(r[:K]) | set(r[-K:])):
    print(s)
