x=int(input())
step=0
for i in range(x):
    j,k=input().split(" ")
    if (int(k)-int(j))>1:
        step+=1
print(step)