d=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
t=int(input())
for _ in range(t):
    n,a,b=map(int,input().split())
    ans=''
    for i in range(b):
        ans+=d[i]
    ans+='a'*(a-b)
    if n%a==0:
        ans*=n//a
    else:
        r=n%a
        tp=ans[:r:]
        ans*=n//a
        ans+=tp
    print(ans)