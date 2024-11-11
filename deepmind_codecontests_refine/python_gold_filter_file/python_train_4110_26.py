x=[]
x=input().split()
a=int(x[0])
b=int(x[1])
c=int(x[2])
d=int(x[3])

m=[]
v=[]
p1=int((3*a)/10)
p2=int(a-((a*c)/250))
m.append(p1)
m.append(p2)

p1=int((3*b)/10)
p2=int(b-((b*d)/250))
v.append(p1)
v.append(p2)

mm=(max(m))
mv=(max(v))

if mm>mv:
    print('Misha')
elif mm==mv:
    print('Tie')
else:
    print('Vasya')