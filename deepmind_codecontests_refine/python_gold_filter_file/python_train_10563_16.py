i=input()
i=i.split()
i1=int(i[1])

b=list()
p=dict()
for j in range(i1):
    k=input()
    i2=k.split()
    if(len(i2[0])<=len(i2[1])):
        p[i2[0]]=i2[0]
    else:
        p[i2[0]]=i2[1]
w=input()
w=w.split()
for l in w:
    m1=p[l]
    b.append(m1)
    b.append(' ')
print(''.join(b).strip())
