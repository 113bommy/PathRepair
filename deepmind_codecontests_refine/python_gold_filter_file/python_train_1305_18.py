ch=input().split()
a,b,c=int(ch[0]),int(ch[1]),int(ch[2])
if c==0:
    if a==b:
        print('YES')
    else:
        print('NO')    
elif (b-a)%c==0 and (b-a)//c>=0  :
    print("YES")
else:
    print('NO')
