w=b=0
d={'q':9,'r':5,'b':3,'n':3,'p':1,'k':0}
for _ in range(8):
    l=list(input())
    for i in l:
        if ord(i)>=65 and ord(i)<=90:
            w=w+d[i.lower()]
        elif ord(i)>=97 and ord(i)<=122:
            b+=d[i]
if w>b:print('White')
elif w<b:print('Black')
else:print('Draw')
    
