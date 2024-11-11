h,w=map(int,input().split())
a=[list(map(int,input().split())) for _ in range(h)]
z=[]
for i in range(w):
  if i%2==0:
    for j in range(h):
      z.append([j,i])
  else:
    for j in range(h):
      z.append([h-j-1,i])
count=0
ans=[]
for i,(y,x) in enumerate(z):
  if a[y][x]%2!=0 and i<len(z)-1:
    count+=1
    ans.append(i)
    a[z[i+1][0]][z[i+1][1]]+=1
print(count)
for i in ans:
  print(z[i][0]+1,z[i][1]+1,z[i+1][0]+1,z[i+1][1]+1)