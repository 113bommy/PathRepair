def s():
 n=int(input())+1
 e=[input().split()for _  in[0]*~-n]
 p=[int(e[0][0])]+list(int(x[1])for x in e)
 m=[[0]*n for _ in[0]*n]
 for i in range(n):
  for r in range(n-i-1):
   c=r+i+1
   for j in range(r+1,c):
    x=m[r][j]+m[j][c]+p[r]*p[j]*p[c]
    if 1>m[r][c]or m[r][c]>x:m[r][c]=x
 print(m[r][c])
if'__main__'==__name__:s()
