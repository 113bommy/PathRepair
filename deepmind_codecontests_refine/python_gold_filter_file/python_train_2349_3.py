a,b = map(int,input().split())
Flag = True
c = [b]
while a != b and Flag:
    if b % 10 == 1:
        b = b // 10
        c.append(b)
    elif b % 2 == 0 and b != 0:
        b = b // 2
        c.append(b)
    else:
        Flag = False
if Flag:
    print ('YES')
    print (len(c))
    c = c[::-1]
    for i in c:
        print (i,end=' ')
else:
    print ('NO')
    

        
