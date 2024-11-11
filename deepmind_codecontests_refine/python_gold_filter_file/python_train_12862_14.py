n=int(input())
t=False
A=[]
for i in range(n):
    x=input()
    if (x[0:2]=="OO" or x[3:]=="OO") and t==False:
        x=x.replace("OO","++",1)
        t=True
    A.append(x)
print(["NO","YES"][t])
if t:
    for i in A:
        print(i)