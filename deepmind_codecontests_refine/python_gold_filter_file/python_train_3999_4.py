n=int(input())
s=1
position=[]
for i in range(n):
    position.append(str(input()))
for j in range(1,n):
    if position[j]!=position[j-1]:
        s=s+1
print(s)
