# import sys
# sys.stdin = open("cf593b.in")

n = int(input())
x1, x2 = map(int, input().split())

k, b = [], []
for _ in range(n):
	kk, bb = map(int, input().split())
	k.append(kk)
	b.append(bb)

at1 = sorted(range(n), key=lambda i: k[i] * (x1 + 1e-8) + b[i])
at2 = sorted(range(n), key=lambda i: k[i] * (x2 - 1e-8) + b[i])

print(["YES", "NO"][at1 == at2])