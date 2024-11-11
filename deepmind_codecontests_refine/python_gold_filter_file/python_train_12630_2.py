t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().rstrip().split()))
    even=0
    odd=0
    for i in a:
        if i%2==0:
            even+=1
        else:
            odd+=1
    if even==odd:
        print("Yes")
    else:
        print("No")