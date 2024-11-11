N, K = map(int, input().split())
P = map(int,input().split())
print(sum(sorted(P)[:K]))