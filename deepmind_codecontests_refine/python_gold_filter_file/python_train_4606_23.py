a = int(input())
l=[]
for x in range(6):
    l.append(a%2)
    a=a//2
a = l[4]*1
a += l[1]*2
a += l[3]*4
a += l[2]*8
a += l[0]*16
a += l[5]*32
print(a)