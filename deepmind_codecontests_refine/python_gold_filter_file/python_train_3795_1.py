n=int(input())
a=[]
b=[]
x=n//2
y=n//2
for i in range(n):
    a.append("*")
    b.append('D')
a[n//2]='D'
for i in range(n//2):
    print(''.join(a))
    x-=1
    y+=1
    a[x]='D'
    a[y]='D'
print(''.join(b))
x=-1
y=n
for i in range(n//2):
    x+=1
    y-=1
    b[x]='*'
    b[y]='*'
    print(''.join(b))