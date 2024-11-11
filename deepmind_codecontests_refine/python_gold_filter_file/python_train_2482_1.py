s=input()
t=input()
l=[]
for i in range(len(s)-len(t)+1):
    for j in range(len(t)):
        if s[i+j]!=t[j] and s[i+j]!='?':
            break
    else:
        a=s[:i]+t+s[i+len(t):]
        l.append(a.replace('?', 'a'))
l.sort()
if l:
    print(l[0])
else:
    print('UNRESTORABLE')