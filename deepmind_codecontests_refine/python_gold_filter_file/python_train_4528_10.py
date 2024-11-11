n=int(input())
l=list(map(int,input().split()))
d=dict()
for i in l:
  if i not in d.keys():
    d[i]=1
  else:
    d[i]+=1
x=0
s=set()
y=list(d.keys())
y.sort()
for i in d.keys():
  while d[i]>1:
    # print(i,d[i],end=': ')
    for j in range(i+1,100000):
      if (j not in d.keys()) and (j not in s):
        # print(j)
        x+=(j-i)
        s.add(j)
        break
    d[i]-=1
print(x)