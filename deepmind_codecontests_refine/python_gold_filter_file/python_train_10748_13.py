for _ in range(int(input())):
    n,x=map(int,input().split())
    lis=list(map(int,input().split()))
    odd=0;even=0
    for i in range(n):
        if lis[i]%2==0:
            even+=1
        else:
            odd+=1
    k=0
    for j in range(1,min(odd,x)+1,2):
        if even>=x-j:
            k=1
            break
    if x==1:
        if odd>=1:
            k=1
    if k:
        print("yes")
    else:
        print("no")
            
