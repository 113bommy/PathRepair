a=input().split()
n=int(a[0]);m=int(a[1])
ans=0
if n<m :
    print('0')
else :
    if n==m:
        print("infinity")
    else :
        i=1
        n=n-m
        while i*i<n:
            if n%i==0:
                if i>m:
                    ans=ans+1
                if n/i>m:
                    ans=ans+1
            i=i+1
        s=int(n**0.5)
        if s**2==n and s>m :
            ans=ans+1
        print(ans)