s=input()+'R'
t=[]
k=0
for i in range(1,len(s)):
  k+=1
  if s[i]!=s[i-1]:
    t+=[k]
    k=0
a=[0]*(len(s)-1)
k=-1
for i in range(len(t)//2):
  k+=t[2*i]
  a[k]=(t[2*i]+1)//2+t[2*i+1]//2
  a[k+1]=t[2*i]//2+(t[2*i+1]+1)//2
  k+=t[2*i+1]
print(*a)