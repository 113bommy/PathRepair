n=int(input())
o=0
y=[]
q=input()
for i in range(len(q)):
    y.append(int(q[i]))
a=y[:]
y.sort()
v=input()
x=[]
for i in range(len(v)):
    x.append(int(v[i]))
b=x[:]
x.sort()
for i in range(len(x)):
    for k in range(len(y)):
        if x[i]>y[k] and y[k]!=-1:
            y[k]=-1
            o=o+1
            break
z=0
a.sort()
b.sort()
for i in range(len(b)):
    for k in range(len(a)):
        if a[k]<=b[i] and a[k]!=-1:
            a[k]=-1
            z=z+1
            break
print(n-z)
print(o)