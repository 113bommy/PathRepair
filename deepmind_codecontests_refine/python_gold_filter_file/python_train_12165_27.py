N, K = map(int,input().split())
L = sorted([list(map(int,input().split())) for _ in range(N)])
for e in L:
    K -= e[1]
    if K <= 0:
        print(e[0])
        exit(0)
