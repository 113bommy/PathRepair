a=int(input())
if a%2==1:
    print(-1)
else:
    for i in range(a,0,-1):
        print(i,end=' ')