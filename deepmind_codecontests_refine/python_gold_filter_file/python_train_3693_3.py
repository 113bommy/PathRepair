# coding: utf-8
s = list(input())
length = len(s)
i = 0
j = length-1
while i < j:
    if s[i] == s[j]:
        i += 1
        j -= 1
    else:
        a = s[:j+1] + [s[i]] + s[j+1:]
        b = s[:i] + [s[j]] + s[i:]
        break
else:
    if len(s)%2==0:
        print(''.join(s[:length//2]+['a']+s[length//2:]))
    else:
        print(''.join(s[:length//2]+[s[length//2]]+s[length//2:]))
    exit()
c = a[::-1]
d = b[::-1]
if a == c:
    print(''.join(a))
elif b == d:
    print(''.join(b))
else:
    print('NA')
