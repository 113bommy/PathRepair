def main():
    n,k,*a=map(int,open(0).read().split())
    for _ in range(k):
        b=[0]*n
        m=10**18
        for i,t in enumerate(a):
            if t<m:m=t
            b[max(0,i-t)]+=1
            if i-~t<n:b[i-~t]-=1
        if m>=n:break
        for i in range(n-1):b[i+1]+=b[i]
        a=b
    print(' '.join(map(str,a)))
main()