n = int(input())
s = input()
t = tuple(map(int, input().split()))
dp = [1]
maxi = 0
for i in range(n):
    ca = 0
    ma = 0
    if i == 0:
        ca += dp[0]
        ma += 1
    else:
        cl = 0
        cp = i
        m = t[ord(s[i]) - 97]
        while cl < m and cp >= 0:
            ca += dp[cp]
            cl += 1
            m = min(m, t[ord(s[cp-1]) - 97])
            cp -= 1
            ma += 1
    if ma > maxi:
        maxi = ma
    dp.append(ca)
print(dp[-1]%(1000000007))
print(maxi)
i = 0
count = 0
cl = 1
while i < n:
    m = t[ord(s[i]) - 97]
    cp = i + 1
    count += 1
    while cl < m and cp < n:
        m = min(m, t[ord(s[cp]) - 97]) 
        if cl < m:
            cl += 1
            cp += 1
        else:
            break
    i = i + cl 
    cl = 1
    cp = i
print(count)
