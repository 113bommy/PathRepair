a=int(input())
for i in range(a):
    b=int(input())
    c=input()
    if b==2 and int(c[0])>=(int (c[1])):
        print('NO')
    else:
        print('YES')
        print(2)
        print(c[0],c[1:b])
