n,k= map(int,input().split())
a= input()
print(a[:k-1]+a[k-1].lower()+a[k:])