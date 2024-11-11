a=int(input())
b=list()
k=0
for i in range(a):
    b.append(input().split())
for i in range(a-1):
    for j in range(i+1,a):
        if b[i][0]==b[j][1]:
            k+=1
        if b[i][1]==b[j][0]:
            k+=1
print(k)
















