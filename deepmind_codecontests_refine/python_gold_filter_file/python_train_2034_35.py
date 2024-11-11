s = ['byte', 'short', 'int', 'long', 'BigInteger ']
q = [2**7, 2**15, 2**31, 2**63]
n = int(input())
res = s[4]
for i in range(4):
    if (n < q[i]): 
        res = s[i]; break
print(res)
