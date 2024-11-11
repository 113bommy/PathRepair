def tentotwo(A):
    c=''
    while A>1:
        c=str(A%2)+c
        A=A//2
    c=str(A)+c
    return c
def twotoeight(c):
    c=str(c)
    if len(c)%3!=0:
        c=(3-len(c)%3)*'0'+c
    c=list(c)
    d=''
    for i in range(len(c)//3):
        s=int(c[3*i])*4+int(c[3*i+1])*2+int(c[3*i+2])
        d=d+str(s)
    return d
def number1(d):
    d.split()
    m=0
    for i in d:
        if int(i)==1:
            m=m+1
    return m
A=eval(input())
c=tentotwo(A)
d=twotoeight(c)
print(number1(d))