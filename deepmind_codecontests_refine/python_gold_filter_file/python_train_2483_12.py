n,m=map(int,input().split())
s=' '.join([input() for _ in [0]*m])
for i in range(1,n+1):print(s.split().count(str(i)))