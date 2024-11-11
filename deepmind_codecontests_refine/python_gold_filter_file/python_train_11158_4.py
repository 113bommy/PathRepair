n=int(input())
a=list(input())
b=list(input())
arr=[]
if a[0]!=a[1]:
    x=a[0]
    y=a[1]
    x1=b[0]
    y1=b[1]
elif b[0]!=b[1]:
    x=b[0]
    y=b[1]
    x1=a[0]
    y1=a[1]
else:
    x=a[0]
    y=a[0]
    x1=b[1]
    y1=b[1]
if x1==x:
    if y1==x:
        for i in range(n):
            arr.append('x')
            arr.append('z')
            arr.append('y')
    else:
        for i in range(n):
            arr.append('z')
        for i in range(n):
            arr.append('y')
        for i in range(n):
            arr.append('x')
elif x1==y:
    if y1==x:
        for i in range(n):
            arr.append('y')
        for i in range(n):
            arr.append('z')
        for i in range(n):
            arr.append('x')
    else:
        for i in range(n):
            arr.append('x')
            arr.append('z')
            arr.append('y')
else:
    if y1==y:
        for  i in range(n):
            arr.append('y')
        for i in range(n):
            arr.append('x')
        for i in range(n):
            arr.append('z')
    else:
        for i in range(n):
            arr.append('x')
            arr.append('z')
            arr.append('y')
answer=''
if x=='a' and y=='b' or x=='b' and y=='a':
    z='c'
elif x=='a' and y=='c' or x=='c' and y=='a':
    z='b'
else:
    if x==y:
        x='a'
        y='b'
        z='c'
    else:
        z='a'
for item in arr:
    if item=='x':
        answer+=x
    elif item=='y':
        answer+=y
    else:
        answer+=z
print('YES')
print(answer)
            
