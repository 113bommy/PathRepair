n=int(input())
t = [list(map(int,input().split())) for i in range(n-1)]
for i in range(n-1):
  ans=t[i][1]+t[i][0]
  for j in range(i+1,n-1):
    if ans>=t[j][1]:
      ans+= -ans%t[j][2]+t[j][0]
    else:
      ans+=t[j][1]-ans+t[j][0]
  print(ans)
print(0)