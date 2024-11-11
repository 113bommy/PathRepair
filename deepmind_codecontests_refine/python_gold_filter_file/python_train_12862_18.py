r=int(input())
j=False
list=[]
for i in range(r):
    n=input()
    if "OO" in n and j==False :
        j=True
        list.append(n.replace("OO","++",1))
    else:
        list.append(n)
if j==True:
    print("YES")
    for i in list:
        print(i)
else:
    print("NO")


