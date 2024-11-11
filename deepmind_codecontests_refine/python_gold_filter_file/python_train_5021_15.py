n = int(input())
s = input()
c = 0
f=0
t=0
for i in s:
    if i == '(':
        c+=1
        if f==1 and c==0:
            t+=1
            f=0
    elif i == ')':
        if c==0:
            f=1
        c-=1
    if f==1:
        t+=1
if c==0:
    print(t)
else:
    print(-1)