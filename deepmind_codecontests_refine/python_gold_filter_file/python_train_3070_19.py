s = input()
t = input()
n = len(s)
count = 0
for i in range(n):
    if s[i]!=t[i]:
        count+=1
if count%2==1:
    print('impossible')
else:
    half = count//2
    count = 1
    p = ['0']*n
    for i in range(n):
        if s[i]==t[i]:
            p[i] = s[i]
        else:
            if count<=half:
                p[i] = s[i]
            else:
                p[i] = t[i]
            count+=1
    print(''.join(p))
