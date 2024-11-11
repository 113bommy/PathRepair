data=list(map(int,input().split()))
n=data[0]
m=data[1]
k=data[2]
pos=[1,1]
if k<=n-1:
    print(k+1,1)
else:
    k-=n-1
    ans=k//(m-1)
    pos=k%(m-1)
    if pos==0 and ans%2 ==0:
        print(n-ans+1,2)
    elif pos==0 and ans%2 !=0:
        print(n-ans+1,m)
    elif pos!=0 and ans%2 ==0:
        print(n-ans,1+k%(2*m-2))
    else:
        print(n-ans,2+(2*m-2)-k%(2*m-2))
