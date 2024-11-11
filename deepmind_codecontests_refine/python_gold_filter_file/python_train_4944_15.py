n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
del a[0]
del b[0]
c=0
while True:
    if a[0]>b[0]:
        a.append(b[0])
        a.append(a[0])
        del a[0]
        del b[0]
    else:
        b.append(a[0])
        b.append(b[0])
        del a[0]
        del b[0]
    c=c+1
    if a==[]:
        print(c)
        print('2')
        break
    elif b==[]:
        print(c)
        print('1')
        break
    elif c>min(2**n,150):
        print('-1')
        break