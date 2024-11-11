n = int(input())

if(n % 2 == 0):
    print(n*n//2)
    for i in range (n//2):
        print('.C'*(n//2))
        print('C.'*(n//2))

else:
    print(n*(n//2) + n//2 + 1)
    for i in range (n):
        if(i % 2 == 0):
            x = ['C']*(n//2+1)
            print(*x,sep='.')
        else:
            x = ['.']*(n//2+1)
            print(*x,sep='C')