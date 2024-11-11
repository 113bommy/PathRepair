n, p, k = map(int, input().split())
s = ''

poc = p - k
kr = p + k + 1

if poc > 1:
    s = '<< '

if poc <= 0:
    poc = 1



for i in range(poc, kr):
    if i <= n:
        if i == p:
            s += '(' + str(i) + ')'
        else:
            s += str(i)

        s += ' '

if str(n) not in s:
    s += '>>'

print(s)
    
