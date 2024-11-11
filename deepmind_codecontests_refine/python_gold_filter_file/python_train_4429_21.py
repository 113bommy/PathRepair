a=list(map(int,input().split()))
b=[0,0]
for i in range (0,2):
	b[i]=list(map(int,input().split()))
#from starting 
st=0
x=0
for j in range (0,a[0]):
	x=x+b[1][j]
	st=st+max(0,b[0][j]-a[1]*x)
#form Ending
ed=0
y=0
for k in range (a[0]-1,-1,-1):
	y=y+b[1][k]
	ed=ed+max(0,b[0][k]-a[1]*y)
if st>ed:
	print("Limak")
if st<ed:
	print("Radewoosh")
if st==ed:
	print("Tie")