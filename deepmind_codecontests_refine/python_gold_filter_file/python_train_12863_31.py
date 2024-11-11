k,r=map(int,input().split())
for i in range(1,11):
    if (k*i)%10==0 or (k*i-r)%10==0:
        print(i)
        break