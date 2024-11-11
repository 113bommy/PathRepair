a = int(input())
s = input()
k = len(s)
vstali = 0
seli = 0
s1 = 'c'

seli = s.count('x')
vstali = s.count('X')

if seli > vstali:
    q = (seli - vstali) // 2
    q1 = q
    k1 = 0
    for i in range(k):
        if s[k1] == 'x' and q1 > 0:
            s1 = s1 + 'X'
            q1 -= 1
        elif s[k1] == 'x' and q1 <= 0:
            s1 = s1 + 'x'
        else:
            s1 = s1 + 'X'
        k1 += 1

if seli < vstali:
    q = (vstali - seli) // 2
    q1 = q
    k1 = 0
    for i in range(k):
        if s[k1] == 'X' and q1 > 0:
            s1 = s1 + 'x'
            q1 -= 1
        elif s[k1] == 'X' and q1 <= 0:
            s1 = s1 + 'X'
        else:
            s1 = s1 + 'x'
        k1 += 1

if seli == vstali:
    s1 = s1 + s
    q = 0

print(q)
print(s1[1:k+1])
