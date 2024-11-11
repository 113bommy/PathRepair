S = 'CODEFORCES'
n = len(S)
s = str(input())
a = False

for i in range(n):
    k = s.find(S[:n - i])
    if k != -1:
        p = k
        while p != -1:
            p = s.find(S[n - i:], p + 1)
            v1 = (k, k + n - i)
            v2 = (p, p + i)
            #print('{} {}'.format(v1, v2))
            if v1[0] == 0 and v2[1] == len(s):
                a = True
            elif (v1[0] == 0 or v2[1] == len(s)) and v2[1] - v1[0] == 10:
                a = True
    
if a:
    print('YES')
else:
    print('NO')