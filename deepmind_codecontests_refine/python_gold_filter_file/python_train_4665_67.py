n=int(input())
da=list(map(int,input().split()))
da=sorted(da)
print(da[n//2]-da[n//2-1])