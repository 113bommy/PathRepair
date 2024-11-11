for time in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    if sum(l)%n != 0:
        print(-1)
    else:
        average = sum(l)//n
        print(3*n-3)
        for i in range(1,n):
            print(1,i+1,(-l[i])%(i+1),sep=" ")
            print(i+1,1,(l[i]+i)//(i+1),sep=" ")
        for i in range(1,n):
            print(1,i+1,average)