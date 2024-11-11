n=int(input())
a=sorted(list(map(int,input().split())))
p=a[n//2-1]
q=a[n//2]
print(q-p)