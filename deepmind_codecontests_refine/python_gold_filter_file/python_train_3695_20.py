n=int(input())
u=input()
z=0
k=0
if n==1:
    print(1)###
else:
    for i in range(n):
        if u[i]=="1":
            z+=1
        else:
            k+=1
    kk=min(z,k)###
    uu=max(z,k)
    print(uu-kk)