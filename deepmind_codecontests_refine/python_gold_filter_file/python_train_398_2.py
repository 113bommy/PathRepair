s = list(input())
t = list(s[::-1])
for i in range(len(s)):
    if t[i] == 'b':
        t[i] = 'd'
    elif t[i] == 'd':
        t[i] = 'b'
    elif t[i] == 'p':
        t[i] = 'q'
    else:
        t[i] = 'p'
if s == t:
    print('Yes')
else:
    print('No')