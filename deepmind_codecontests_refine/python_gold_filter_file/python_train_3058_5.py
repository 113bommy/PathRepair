a,b,n=map(int,input().split())
digits=[0,1,2,3,4,5,6,7,8,9]
length,prev=1,1
flag=False
ans=str(a)
if a%b==0:
    ans+="0"*n
    print(ans)
else:
    for i in range(10):
        cum=str(a)+str(digits[i])
        if int(cum)%b==0:
            ans=cum
            break
    else:
        print(-1)
        flag=True

    if flag==False:
        ans+=("0"*(n-1))
        print(ans)