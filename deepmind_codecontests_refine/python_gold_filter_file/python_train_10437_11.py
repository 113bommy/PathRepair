for _ in range(int(input())):
    x = int(input())
    l=list(map(int,input().split()))
    
    for i in range(len(l)):
        if(i%2 and l[i]<0):
            l[i]=l[i]*(-1)
        if(i%2==0 and l[i]>0):
            l[i]*=-1
    for _ in range(len(l)):
        print(l[_],' ')