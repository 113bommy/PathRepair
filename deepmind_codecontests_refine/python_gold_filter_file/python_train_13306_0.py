l=bin(int(input()))[2:];n=len(l);print(n,2*n+l.count("1")-3)
for i in range(1,n):print(i,i+1,0);print(i,i+1,1<<(i-1))
w=1<<(n-1)
for i in range(1,n)[::-1]:
  if l[n-i]=="1":print(i,n,w);w+=1<<(i-1)