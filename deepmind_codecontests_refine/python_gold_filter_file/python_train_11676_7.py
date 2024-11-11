n=int(input())
cnt=9
while(n//10!=0):
    cnt+=10-n%10
    n+=(10-n%10)
    while(n%10==0):
        n=n//10
print(cnt)

