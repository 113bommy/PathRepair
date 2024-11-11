n,k=map(int,input().split())
for i in range(1,10):
    if (n*i)%10==k or (n*i)%10==0:
        print(i)
        break