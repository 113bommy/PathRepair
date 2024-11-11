naual=list(input().strip().split())
n=int(naual[0])
au=naual[1]
al=naual[2]
#print(n,au,al)
auther=list(map(int,input().strip().split()))
alex=list(map(int,input().strip().split()))

for i in range(1,n+1):
  if(au>=al):
    if(i in auther):
      print("1",end=" ")
    elif(i in alex):
      print("2",end=" ")
  elif(al>=au):
    if(i in alex):
      print("2",end=" ")
    elif(i in auther):
      print("1",end=" ")

