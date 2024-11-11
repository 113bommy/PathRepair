def char_to_int(c):
    res = ord(c) - ord('a')
    return res

def int_to_char(n):
    n_ord = ord('a') + n
    res = chr(n_ord)
    return res 

n = int(input())
s = input()

maxdp = [0] * 26

dp = [1] * n
for i in range(n):
    si = s[i]
    isi = char_to_int(si)
    for c in range(25, isi, -1):
        dp[i] = max(dp[i], maxdp[c] + 1)
    maxdp[isi] = max(maxdp[isi], dp[i])

m = max(maxdp)
print(m)
print(" ".join(map(str, dp)))
# for i in range(n):
#     print(dp[i])