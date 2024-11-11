n=int(input())
m=[]
for i in range(n):
     m.append(list(input()))
     
for i in range(n-2):
     for j in range(1,n-1):
          if m[i][j]==".":
               if m[i+1][j]=="." and m[i+2][j]=="." and m[i+1][j-1]=="." and m[i+1][j+1]==".":
                    m[i+1][j]="#"
                    m[i][j]="#"
                    m[i+2][j]="#"
                    m[i+1][j-1]="#"
                    m[i+1][j+1]="#"
for i in range(n):
     for j in range(n):
          if m[i][j]==".":
               print("NO")
               exit()
print("YES")