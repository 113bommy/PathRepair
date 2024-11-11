import math
N = int(input())
A = list(map(int, input().split()))

maxA = max(A) + 1

C = [0] * maxA

g = 0

for a in A:
    C[a] += 1
    g = math.gcd(g, a)

pairwise = True

for i in range(2, maxA):
    cnt = 0
    for j in range(i, maxA, i):
        cnt += C[j]

    if cnt > 1:
        pairwise = False

if pairwise:
    print("pairwise coprime")
    exit()

if g == 1:
    print("setwise coprime")

else:
    print("not coprime")