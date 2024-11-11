mod = int(1e9) + 7

n = int(input())
s1 = input()
s2 = input()

if s1[0] == s2[0]:
    ans = 3
    i = 1
else:
    ans = 6
    i = 2
while i < n:
    #print(ans, i,s1[i],s2[i],s1[i-1],s2[i-1])
    if s1[i] == s2[i]:

        if s1[i-1] == s2[i-1]:
            ans *= 2
            ans %= mod
        i += 1
    else:

        if s1[i-1] == s2[i-1]:
            ans *= 2
            ans %= mod
        else:
            ans *= 3
            ans %= mod
        i += 2
print(ans)