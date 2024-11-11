n=int(input())
a=input()
d=a
for i in range(10):
    for j in range(n):
        a=a[n-1]+a[:n-1]
        if a<d:
            d=a
    l=list(a)       
    for j in range(n):
        l[j]=chr(ord(l[j])+1)
        if l[j]==':':
            l[j]='0'
    a="".join(l)
    if a<d:
        d=a

print (d)