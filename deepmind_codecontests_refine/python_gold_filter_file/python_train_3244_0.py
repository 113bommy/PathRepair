t=int(input())
for i in range(t):
    n=int(input())
    arr=[int(i) for i in input().strip().split(' ')]
    n2=0
    n1=0
    n3=0
    for i in arr:
        if i%3==0:
            n3+=1
        elif i%3==2:
            n2+=1
        else:
            n1+=1
    if n1>n2:
        ans=n3+n2+(n1-n2)//3
    else:
        ans=n3+n1+(n2-n1)//3
        
    print(ans)
    