def main():
    from itertools import accumulate as ac
    from bisect import bisect_left as bl
    from bisect import bisect_right as br
    from sys import stdin
    input=stdin.readline

    def check(k):
        dist=a[-k-1]-ini
        if dist<0:
            dist=abs(dist)
            return k>=br(a,ini+dist)-bl(a,ini-dist)-1
        else:
            return k>=br(a,ini+dist)-bl(a,ini-dist)
    
    n,q=map(int,input().split())
    nn=n//2+1
    a=list(map(int,input().split()))
    x=[int(input()) for _ in [0]*q]
    ix=sorted([[i,j] for i,j in enumerate(x)],key=lambda x:x[1])
    ans=[0]*q
    aac=[0]+list(ac(a))
    aac2=[0]+list(ac(a[(n+1)%2::2]))
    k=min(nn,n-1)

    for i,ini in ix:
        while check(k)==True:k-=1
        k+=1
        ans[i]=aac[-1]-aac[-k-1]+aac2[-k-1]
    for i in ans:
        print(i)
main()