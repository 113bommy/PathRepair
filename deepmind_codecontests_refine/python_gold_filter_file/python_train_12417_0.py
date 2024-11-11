s=str(input())
a=len(s)
z=(10**9)+7
if a==1:
    print(0)
else:
    lis=[]
    power=[1]
    for i in range(1,a):
        if i!=1:
            power.append((power[-1]*10)%z)
        lis.append((power[-1]*i)%z)
    pref=[lis[0]]
    for i in range(1,a-1):
        pref.append((pref[-1]+lis[i])%z)
    ans=0
    for i in range(a):
        back=i
        front=a-i-1
        if i>0:
            temp=((back*(back+1))//2)*power[front]
            temp%=z
            temp*=int(s[i])
            temp%=z
            ans+=temp
            ans%=z
        if i<a-1:
            temp=pref[-i-1]
            temp*=int(s[i])
            temp%=z
            ans+=temp
            ans%=z
    print(ans)