from math import ceil
n,t=map(int,input().split());ans=[]
for i in range(n):
  a,b=map(int,input().split())
  if a>=t:ans.append(a-t)
  else :
    n1=ceil(abs(t-a)/b);k1=a+n1*b;ans.append(abs(t-k1))
minn=10**5;ans1=0
for i in range(n):
  if minn>ans[i]:minn=ans[i];ans1=i+1
print(ans1)
