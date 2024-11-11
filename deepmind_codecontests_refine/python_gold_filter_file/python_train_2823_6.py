def compare(s1,s2):
    x = "6 7 8 9 T J Q K A".split()
    for i in range (9):
        if s1 == x[i]:
            t1 = i
        if s2 == x[i]:
            t2 = i
    return t1 > t2

n = input()
res = 'NO'
s = input().split()
if s[0][1] == s[1][1]:
    if compare(s[0][0],s[1][0]):
        res = 'YES'
else:
    if s[0][1] == n:
        res = 'YES'

print(res)