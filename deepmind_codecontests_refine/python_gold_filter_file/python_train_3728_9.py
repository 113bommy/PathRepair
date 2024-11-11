import sys

input = sys.stdin.readline

X, Y, Z, K = map(int, input().split())
a = map(int, input().split())
b = list(map(int, input().split()))
c = map(int, input().split())

d = (aa + bb for aa in a for bb in b)
d = sorted(d, reverse=True)[:K]

e = (cc + dd for cc in c for dd in d)
e = sorted(e, reverse=True)[:K]

print('\n'.join(map(str, e)))