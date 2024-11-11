t=int(input())
for _ in range(t):
    n,x=map(int,input().split())
    num=list(map(int,input().split()))
    even=odd=0
    for v in num:
        if(v%2==0):
            even+=1
        else:
            odd+=1
    flag=0
    for val in range(1,min(odd,x)+1,2):
        if(x-val)<=even:
            flag=1
            break
    if(flag):
        print("Yes")
    else:
        print("No")
