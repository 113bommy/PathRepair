s=[int(i) for i in input()]
n=len(s)
ans=0
f=0
for i in range(n-1,-1,-1):
  j=s[i]+f
  if j<5:
    ans+=j
    f=0
  elif j>5:
    ans+=10-j
    f=1
  elif i and s[i-1]>=5:
    ans+=10-j
    f=1
  else:
    ans+=j
    f=0
print(ans+f)