N, K = map(int, input().split())
A = list(map(int, input().split()))


def countMask(a):
    ret = 0
    for x in cand:
        if (x & a) == a:
            ret += 1
    return ret


cand = []
for i in range(N):
    sum = 0
    for j in range(i, N):
        sum += A[j]
        cand.append(sum)

ans = 0

for i in range(40, -1, -1):
    if (countMask(ans | (1 << i)) >= K):
        ans |= 1 << i

print(ans)
