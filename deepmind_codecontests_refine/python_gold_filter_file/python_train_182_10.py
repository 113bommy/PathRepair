s=input()*2;n=len(s)//2;X=[(0,0)]*4
for j in range(n+1):
 for k in range(3,-1,-1):
  a=int(s[n-j])
  X[k]=(X[k][0]+9*X[k-1][0],X[k][0]+(a-1)*X[k-1][0]+X[k-1][1]if a else X[k][1])if k else(1,1)
print(X[int(input())][1])