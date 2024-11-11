s=input()
n=len(s)
ca=[0]*(n+1)
cb=[0]*(n+1)
for i in range(n):
  if s[i]=="a":
    ca[i+1]+=1
  else:
    cb[i+1]+=1
for i in range(n):
  ca[i+1]+=ca[i]
  cb[i+1]+=cb[i]
ans=min(ca[-1],cb[-1])
for l in range(1,n+1):
  ans=min(ans,ca[l]+(cb[-1]-cb[l]))
  ans=min(ans,cb[l]+(ca[-1]-ca[l]))
  for r in range(l,n+1):
    ans=min(ans,cb[l]+(ca[r]-ca[l])+(cb[-1]-cb[r]))
print(n-ans)