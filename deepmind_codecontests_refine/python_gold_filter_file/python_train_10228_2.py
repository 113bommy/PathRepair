for i in range (int(input())):
    a,b=map(int,input().split())
    if a>=(b**2) and a%2==b%2:
        print("YES")
    else:print('NO')
