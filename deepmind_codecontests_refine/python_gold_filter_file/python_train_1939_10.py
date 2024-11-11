n = int(input())
s = list(map(int, input().split()))
s = list(sorted(s))
ansm = 100000000
for i in range(len(s)):
    s1 = s[:i] + s[i+1:]
    for j in range(len(s1)):
        s2 = s1[:j]+s1[j+1:]
        ans = 0
        for i in range(1, 2*n - 2, 2):
            ans += s2[i] - s2[i-1]
        if ans < ansm:
            ansm = ans
print(ansm)