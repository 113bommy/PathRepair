x=sum(list(map(int,input().split())))
if x>0 and x%5==0:
    print(x//5)
else:
    print(-1)