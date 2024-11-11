x,y,z=map(int,input().split())
p=[]
p.append(str((x+y)//z))
a=x%z
b=y%z
#print(a,b)
if b>a:
    a,b=b,a
if (z-a)<=b:
    p.append(str(z-a))
    #print('Fjof')
else:
    p.append(str(0))
print(' '.join(p))
