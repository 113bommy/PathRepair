a,b,c=map(int,input().split())
if c==0: 
    print('YES' if b==a else 'NO')
else:
     if (b-a)%c==0 and (b-a)//c>=0: print('YES')
     else: print('NO')