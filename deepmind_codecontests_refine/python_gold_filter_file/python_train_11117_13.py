n,m = map(int,input().split())
ac,wa = 0,0
number=[0]*n

for i in range(m):
  p,s = input().split()
  p = int(p) - 1
  if number[p]!=-1:
    if s == "WA":
      number[p]+=1
    elif s == "AC":
      ac+=1
      wa+=number[p]
      number[p]=-1
print(ac,wa)