a,b=[int(i) for i in input().split()]
s=[int(i) for i in input().split()]
m=1
c=b
for i in range(a):
    if s[i]>c:
        m=m+1
        c=b-s[i]
    else:
        c=c-s[i]
print(m)
