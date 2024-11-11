for _ in range(int(input())):
    n , m = map(int,input().split())
    
    sharededges = n*(m-1) + m*(n-1)
    
    if(n*m >= sharededges):print("YES")
    else:print("NO")