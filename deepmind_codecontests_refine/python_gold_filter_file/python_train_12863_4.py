n1,n=map(int,input().split())
i=1
while(1):
    if ((n1*i)-n)%10==0 or (n1*i)%10==0:
        print(i)
        break
    i+=1