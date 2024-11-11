x=str(input())
y=str(input())
def f(i,o):
    m=(int(i[0])-int(o[0]))**2+(int(i[1])-int(o[1]))**2+(int(i[2])-int(o[2]))**2
    if(m==1 or m==2):
        return True
    return False
a,b,l,m=[],[],[],[]
a=x.split(' ')
b=y.split(' ')
l=[y for y in a if y!='']
m=[y for y in b if y!='']
if(f(l,m)==True):
    print("YES")
else:
    print("NO")