n=int(input())
c=[["."]*n for i in range(n)]
ans=0
for i in range(n):
     for j in range(n):
          if i&1==0 and j&1==0:
               c[i][j]="C"
               ans+=1
          if i&1==1 and j&1==1:
               c[i][j]="C"
               ans+=1
print(ans)
for i in range(n):
     print("".join(c[i]))
     
