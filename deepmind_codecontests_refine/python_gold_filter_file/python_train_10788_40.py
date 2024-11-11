n=int(input())

liste=[]
for i in range(n):
    a,b=(input()).split(" ")
    liste.append((int(a),int(b)))

which_side=[]
for (a,b) in liste:
    which_side.append( a>0 )
if which_side.count(0)>1 and which_side.count(1)>1:
    print("No")
else:
    print("Yes")