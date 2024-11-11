n,m=map(int,input().split())
nn=""
mm=[]
for i in range(n):
    nn+=input()+"\n"
for i in range(m):
    mm.append(input()+"\n")
count=0
for i in range(m):
    if(mm[i] in nn ):
        count+=1

if(count==m):
    print("Yes")
else:
    print("No")
