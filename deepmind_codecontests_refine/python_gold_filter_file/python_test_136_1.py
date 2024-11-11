t = int(input())
for _ in range(t):
    n = int(input())
    B = list(map(int,input().split()))
    
    net = 0
    if sum(B) % ( n*(n+1)//2 ) != 0:
        print("NO")
        continue
        
    
    net += sum(B) // ( n*(n+1)//2 )
    A = []
    flag = True
    
    for i in range(n):
        if (net + B[(i-1)%n] - B[i]) <= 0 or (net + B[(i-1)%n] - B[i]) % n != 0 :
            print("NO")
            flag = False
            break
        
        x = (net + B[(i-1)%n] - B[i]) // n
        A.append(x)
    
    if flag:
        print("YES")
        for val in A:
            print(val, end = " ")
        print()
    

