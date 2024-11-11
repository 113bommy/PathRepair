n,k=map(int,input().split())
a=input()
a=a[:k-1]+a[k-1].lower()+a[k:]
print(a)