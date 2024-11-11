def fun(n):
    for i in range(2,int(n**0.5)+1):
        x=n//i
        if n%i==0:
            for j in range(2,int(x**0.5)+1):
                if x%j==0 and x//j!=j and i!=j and x//j!=i:
                    return True,[i,j,x//j]
    return False,[-1,-1,-1]
    
t=int(input())
for _ in range(t):
    n=int(input())
    
    res,lst = fun(n)
    lst.sort()
    if res:
        print("YES")
        print(lst[0],lst[1],lst[2])
    else:
        print("NO")