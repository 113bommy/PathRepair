t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    cnt=99999999999999999999999999999999999999999
    ans=[0,0,0]
    for i in range(1,15000+1):
        s=abs(i-a)
        temp=s
        j=i*1
        o=1
        while j<=15000:
            temp += abs(j-b)
            f=c//j
            l,h=f*j,(f+1)*j
            kk=h
            if abs(l-c)<abs(h-c):
                kk=l
            temp += abs(kk-c)
            if temp<cnt:
                cnt=temp
                ans[0]=i
                ans[1]=j
                ans[2]=kk
            temp=s
            o += 1
            j=i*o
    print(cnt)
    print(" ".join(map(str,ans)))