a,b,c,d,e,f=map(int,input().split())
aa=-1
ans=[0,0]
for i in range(0,f+1,a*100):
  for j in range(0,f+1-i,b*100):
    for k in range(0,int(e*(i+j)/100)+1,c):
      for l in range(0,int(e*(i+j)/100)+1-k,d):
        if i+j+k+l>f:
          continue
        if i+j>0 and aa<(k+l)/(i+j+k+l):
          aa=(k+l)/(i+j+k+l)
          ans=[i+j+k+l,k+l]
print(ans[0],ans[1])
        