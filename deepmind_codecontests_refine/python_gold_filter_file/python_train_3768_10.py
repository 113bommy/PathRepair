for i in range(int(input())):
    a = int(input())
    li = list(map(int,input().split()))
    print(-(-sum(li)//a))