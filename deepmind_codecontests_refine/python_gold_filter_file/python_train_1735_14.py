def v3(x):
    ans = 0
    while x % 3 == 0:
        x //= 3
        ans += 1
    return ans
def v2(x):
    ans = 0
    while x % 2 == 0:
        x //= 2
    return ans

n = int(input())
arr = sorted(map(int, input().split()))
d = set()
mxpow3 = 0
pow3 = 0
mnpow2 = 1000
pow2 = 0
for num in arr:
    d.add(num)
    if v3(num) > mxpow3:
        mxpow3 = v3(num)
        pow3 = num
    if v2(num) < mnpow2:
        mnpow2 = v2(num)
        pow2 = num
cur = 0
tot = 0
if mxpow3 == 0:
    print(pow2,end = " ")
    cur = pow2
    tot += 1
else:
    print(pow3, end = " ")
    cur = pow3
    tot += 1

while tot < n:
    if 2 * cur in d:
        cur = 2 * cur
        print(cur, end = " ")
    else:
        cur //= 3
        print(cur, end = " ")
    tot += 1

        
