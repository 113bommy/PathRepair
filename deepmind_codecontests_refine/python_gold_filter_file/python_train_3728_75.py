x,y,z,k=map(int,input().split());a,b,c=list(map(int,input().split())),list(map(int,input().split())),list(map(int,input().split()))
aa=[]
for i in a:
  for j in b:aa.append(i+j)
aa.sort(reverse=1)
aa=aa[:k+1]
s=[]
for i in aa:
  for j in c:s.append(i+j)
s.sort(reverse=1)
for i in range(k):print(s[i])