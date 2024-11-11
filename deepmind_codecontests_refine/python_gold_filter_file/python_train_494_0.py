from collections import defaultdict

def gcd(a, b):
    return gcd(b, a%b) if b else a

mod = 10 ** 9 + 7
N = int(input())
X = defaultdict(lambda: [0, 0])
# X = dict()
x = 0
y = 0
z = 0
for i in range(N):
    a, b = map(int, input().split())
    g = abs(gcd(a, b))
    if a * b > 0:
        X[(abs(a) // g, abs(b) // g)][0] += 1
    elif a * b < 0:
        X[(abs(b) // g, abs(a) // g)][1] += 1
    else:
        if a:
            x += 1
        elif b:
            y += 1
        else:
            z += 1
# suppose we have a super head point which can put togother with every point.
ans = 1
pow2 = [1]
for i in range(N):
    pow2 += [pow2[-1] * 2 % mod]
for i in X.values():
    ans *= pow2[i[0]] + pow2[i[1]]- 1
    ans %= mod
ans *= pow2[x] + pow2[y] - 1
print((ans+z-1)%mod)
