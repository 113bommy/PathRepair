n=int(input())
s=input()
mx=0
for i in range(1,n):
  c=0
  for j in range(n-i):
    if s[j]==s[j+i]:
      c+=1
      mx=max(mx,c)
      if c==i:
        break
    else:
      c=0
print(mx)
