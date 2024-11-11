n=input().split()
z=input().split()
house=int(n[0])
girl=int(n[1])-1
money=int(n[2])
a=list(map(lambda x:money>=int(x)and int(x)!=0,z))
b=set()
for i in range(len(a)):
    if a[i]:
        b.add(abs((i)-girl)*10)
if len(b)>0:
    print(min(b))
else:
    print(float("inf"))
