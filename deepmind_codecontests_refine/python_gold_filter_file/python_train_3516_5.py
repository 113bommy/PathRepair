n=int(input())
a=list(map(int,input().split()))
al=0
for i in a:
  al=al^i
r=""
for i in a:
  r+=str(i^al)+" "
print(r[:-1])
