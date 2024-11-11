N, X = map(int, input().split())
L = [int(input()) for i in range(N)]
print((X-sum(L))//min(L)+N)