def stairs(n,m):
    arr=list()
    for i in range(n):
        if 2*i<=n and (n-i)%m==0:
            arr.append(i)
    if arr:        
        steps_2=max(arr)
        steps_1=n-(2*steps_2)
        total_steps=steps_2+steps_1
        print(total_steps)
    else:
        print(-1)

n,m=input().split()
stairs(int(n),int(m))
            

