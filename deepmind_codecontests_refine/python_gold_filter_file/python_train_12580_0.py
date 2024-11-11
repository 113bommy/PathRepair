n,m=map(int,input().split())
a=sorted([int(i) for i in input().split()])
print(sum(a[-m:]))