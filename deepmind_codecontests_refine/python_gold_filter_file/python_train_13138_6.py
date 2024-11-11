s = input()
def count_unique_substring(s):
    n = len(s)
    p = 31
    m = 10**9 + 9
    p_pow = [1]
    for i in range(1,n):
        p_pow.append((p_pow[i-1]*p)%m)
    hash = [0]
    count = 0
    flag=0
    for i in range(n):
        hash.append(( hash[i] + (ord(s[i])-ord('a')+1) * p_pow[i]) % m)
    for l in range(n,0,-1):
        c_1 = (hash[ l] + m - hash[0]) % m
        c_1 = c_1 * p_pow[n - 1] % m
        c_2 = (hash[n-l + l] + m - hash[n-l]) % m
        c_2 = c_2 * p_pow[l - 1] % m
        if c_1 == c_2:
            for i in range(1,n-l):
                c_h = (hash[i+l] + m - hash[i]) % m
                c_h = c_h * p_pow[n-i-1]%m
                if c_h == c_2:
                    return (s[i:i+l])

t = count_unique_substring(s)
if t:
    print(t)
else:
    print('Just a legend')
