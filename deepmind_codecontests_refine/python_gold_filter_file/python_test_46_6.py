
test=int(input())
while(test):
    n=int(input())
    a=list(map(int,input().split()))
    an=a[n-1]
    max=0
    count=0
    i=n-1
    while(i>=0):
        if a[i]>max:
            max=a[i]
            count+=1
        i=i-1
    print(count-1)
    test=test-1