a=list(map(int,input().split()))
f1=0
f2=0
for i in a:
    if a.count(i)>=4:
        f1=1
    elif a.count(i)==1:
        f2=1
if f1==0:
    print('Alien')
else:
    if f2==0:
        print('Elephant')
    else:
        print('Bear')
