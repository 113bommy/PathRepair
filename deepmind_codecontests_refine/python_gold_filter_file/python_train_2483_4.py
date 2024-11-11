n,m=map(int,input().split());a=[]
for _ in[0]*m:a+=input().split()
for x in range(n):print(a.count(str(-~x)))