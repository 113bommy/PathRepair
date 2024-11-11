__author__ = 'Utena'
def t(x):
    a=''
    for l in x:
        if l=='+':
            a+='*'
        elif l=='*':
            a+='+'
    return a
k=int(input())
if k==0:
    print('+')
    exit(0)
m=['++','+*']
s=1
for i in range(k-1):
    m=m+m
    s*=2
    for j in range(s):
        m[j]+=m[j]
        m[s+j]+=t(m[s+j])
for y in m:
    print(y)