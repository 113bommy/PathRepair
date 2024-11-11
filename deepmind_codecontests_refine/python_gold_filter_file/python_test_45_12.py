for i in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    x=1
    if l[0] == 0 and len(l) == 1:
        print(1)
    else:
        for i in range(n):
            
            if i>=1 and l[i] ==1 and l[i-1] == 1:
                x+=5
                
            elif l[i] == 1:
                x+=1
                
            
            elif i<n-1 and l[i] ==0 and l[i+1] ==0:
                x=-1
                break
            
        print(x)