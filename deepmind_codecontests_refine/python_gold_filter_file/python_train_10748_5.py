t= int(input())
while(t>0):
    n,x = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    e = 0
    odd = 0
    for i in a:
        if i%2==0:
            e+=1
        else:
            odd+=1
    if odd == 0:
        print('NO')
    else:
        if odd%2==0:
            odd-=1
        if e==0 and x%2==0:
            print('NO')
        elif (odd+e)>=x:
            print('YES')
        else:
            print('NO')
    t-=1
                
                
    
