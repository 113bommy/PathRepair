n=int(input())
for i in range(n):
    t=input()
    if int(t)==0 or int(t)==1:
        print(1,end=" ")
    if int(t)!=1:
        for j in range(1,int(t)+1):
            print(j,end=" ")
    print()