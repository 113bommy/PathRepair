n=int(input())
b=[]
for i in range(n):
    a=input()
    b.append(a)
for i in range(n):
    if 'OO' in b[i]:
        if b[i][0]=='O' and b[i][1]=='O':
            b[i]='++'+'|'+b[i][3]+b[i][4]
            print('YES')
            print('\n'.join(b))
            break
        else:
            b[i]=b[i][0]+b[i][1]+'|'+'++'
            print('YES')
            print('\n'.join(b))
            break
    elif i==n-1:
        print('NO')
   



    


