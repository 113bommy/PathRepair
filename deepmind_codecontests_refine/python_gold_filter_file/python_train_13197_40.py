n=int(input())
a=list(map(int,input().split()))
a.sort(reverse=True)
print( sum( a[i//2] for i in range(1,n)) )