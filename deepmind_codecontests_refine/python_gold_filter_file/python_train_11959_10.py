while True:
    n = int(input())
    sumlist=[]
    sum=0
    max=-100000
    if n==0:
        break
    for i in range(n):
         sumlist.append(int(input()))
    for i in range(n):
        sum=0
        for j in range(0,n-i):
            sum=sumlist[i+j]+sum
            if max<sum:
                max=sum

    print(max)