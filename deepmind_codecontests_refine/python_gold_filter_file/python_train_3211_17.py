import sys
sys.setrecursionlimit(10**7)
INF=10**18

def main():
    N,Z,W=map(int,input().split())
    a=list(map(int,input().split()))
    dic={}
    def rec(z,w,now,t):
        if dic.get((now,t),None)!=None:
            return dic[(now,t)]
        if now>=N-1:
            return abs(z-w)
        if not t:
            res=-INF
            for i in range(now+1,N):
                r=rec(a[i],w,i,1)
                res=max(res,r)
        else:
            res=INF
            for i in range(now+1,N):
                r=rec(z,a[i],i,0)
                res=min(res,r)
        dic[(now,t)]=res
        return res

    return rec(Z,W,-1,0)
    
print(main())
