n=input()
b=n.split()
a=[]
for i in range(len(b)):
    a.append(int(b[i]))
s=input()
c=list(s)
d=[]
for i in range(len(c)):
    d.append(int(c[i]))
cal=0
for i in range(len(d)):
    cal=cal+a[d[i]-1]
print(cal)