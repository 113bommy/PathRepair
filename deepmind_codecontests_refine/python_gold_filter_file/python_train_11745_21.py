def count(n,x):
    if x<=n:
        return 0
    elif x>=2**(n+2)-3-n:
        return 2**(n+1)-1
    elif 2**(n+2)-3 > 2*x:
        return count(n-1,x-1)
    else:
        return 2**n + count(n-1,x-2**(n+1)+1)

n,x=map(int,input().split())
print(count(n,x))