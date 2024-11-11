from collections import Counter

N = int(input())
A = list(map(int, input().split()))

maxPow = (1 << (max(A) * 2).bit_length())
cntA = Counter(A)

ans = 0
while maxPow > 0:
    for a in A:
        if maxPow - a == a:
            if cntA[a] >= 2:
                ans += cntA[a] // 2
                cntA[a] %= 2
        elif cntA[a] > 0 and cntA[maxPow - a] > 0:
            ans += 1
            cntA[a] -= 1
            cntA[maxPow - a] -= 1
    maxPow //= 2

print(ans)