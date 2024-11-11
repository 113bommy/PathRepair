for _ in range(int(input())):
    a,b,n,s=map(int,input().split())
    value=int(s/n)
    if value<=a:
        rem=s%n
        if rem<=b:
            print("YES")
        else:
            print("NO")
    else:
        s=s-(n*a)
        if s>b:
            print("NO")
        else:
            print("YES")
    
      
