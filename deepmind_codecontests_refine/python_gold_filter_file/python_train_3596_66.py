mad_kid=0
signs=[]
num=[]
n,x=map(int,input("").split())
for i in range (0,n):
    d=input("")
    num.append(d[2:])
    signs.append(d[0])

for j in range (0,len(signs)):
    if signs[j]=="+":
        x+=int(num[j])
     
    elif signs[j]=="-":
        if x >= int(num[j]):
            x-=int(num[j])
           
        else:
            mad_kid+=1
print(x,mad_kid)