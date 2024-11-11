#Badges
b=int(input())
g=int(input())

n=int(input())

out=0
for i in range(b+1):
    for j in range(g+1):
        if (i+j==n):
            out+=1
print(out)