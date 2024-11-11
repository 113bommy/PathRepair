n = int(input())
l = list(map(int,input().split()))
if(n==1):
    print(-1)
    exit(0)
elif(n==2):
    if(l[1]==l[0]):
        print(-1)
    else:
        print(1)
        print(1)
else:
    print(1)
    print(l.index(min(l))+1)