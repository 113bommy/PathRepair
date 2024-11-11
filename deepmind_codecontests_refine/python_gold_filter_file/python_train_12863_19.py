n,m=map(int,input().split())
for i in range(1,11):
    if (n*i)%10==0 or (n*i)%10==m:
        print(i)
        break
