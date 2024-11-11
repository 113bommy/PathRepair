k=0
x=int(input())
n=map(int,input().split())
for j in n:
    if(j!=0):
        k+=1
if(k>0):
    print("HARD")
else:
    print("EASY")