def resolve():
    import math
    from math import gcd
    MOD=10**9+7
    n=int(input())
    zero=0
    cnt={}
    for i in range(n):
        a,b=map(int,input().split())
        if a==0 and b==0:
            zero+=1
            continue
        g=gcd(a,b)
        a//=g
        b//=g
        if b<0:
            a*=-1
            b*=-1
        if b==0 and a<0:
            a*=-1
        if a<=0:
            a,b=b,-a
            if (a,b) in cnt:
                cnt[(a,b)][0]+=1
            else:
                cnt[(a,b)]=[1,0]
        else:
            if (a,b) in cnt:
                cnt[(a,b)][1]+=1
            else:
                cnt[(a,b)]=[0,1]
    ans=1
    for i,v in cnt.items():
        ans*=pow(2,v[0],MOD)+pow(2,v[1],MOD)-1
        ans%=MOD
    print((zero-1+ans)%MOD)    

if __name__ == '__main__':
    resolve()