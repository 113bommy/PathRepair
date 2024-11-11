n,x,y=map(int,input().split())
n//=2
if [x,y] in [[n,n],[n,n+1],[n+1,n],[n+1,n+1]]:print("NO")
else:print("YES")