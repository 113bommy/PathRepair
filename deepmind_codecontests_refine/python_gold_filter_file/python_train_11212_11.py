a=int(input())
b=list(map(int,input().split()))
if a==1 or (a==2 and b[0]==b[1]):
    print(-1)
else:
    for i in range(1,a):
        if sum(b[:i])!=sum(b[i:]):
            print(len(b[:i]))
            for k in range(1,i+1):
                print(k,end=' ')
            break







