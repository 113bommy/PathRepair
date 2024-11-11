n=int(input())
a=[]
a+=map(int,input().split())
a.sort()
print(a[n//2-(n+1)%2])
