a=int(input())
for i in range(0,a):
    n,k=map(int,input().split())
    sol=[]
    if(n%2==0):
        if(k*2>n):
            if(k%2==0):
                if(k>n):
                    print("NO")
                else:    
                    for i in range(0,k-1):
                        sol.append(1)
                    sol.append(n-k+1)  
            else:
                print("NO")
        else:
            for i in range(0,k-1):
                sol.append(2)
            sol.append(n-(k-1)*2)    
    else:
        if(k>n):
            print("NO")
        else:
            if(k%2==0):
                print("NO")
            else:
                for i in range(0,k-1):
                    sol.append(1)
                sol.append(n-k+1)
    if(len(sol)>0):
        print("YES")
        print(" ".join(list(map(str,sol))))
                