input()
a=list(map(int,input().split()))
s=sum(a)
print(s-min(i for i in a if i%2) if s%2 else s)