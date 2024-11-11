h,w=map(int,input().split())
lll=[list("."*(w+2))]
G=[list("."+input()+".") for _ in range(h)]
G=lll+G+lll
#print(G)
for i in range(1,h+1):
  for j in range(1,w+1):
    if G[i][j]=="#" and G[i-1][j]==G[i+1][j]==G[i][j-1]==G[i][j+1]==".":
      print("No")
      exit()
print("Yes")  
