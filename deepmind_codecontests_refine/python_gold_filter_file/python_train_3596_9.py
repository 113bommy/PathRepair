nx = input().split(" ")
n = int(nx[0])
x = int(nx[1])
m=list()
c=0
for i in range(n):
    d = input()
    m = m + [d]
for i in range(n):
    k=m[i].split(" ")
    if(k[0]=="+"):
        x = x + int(k[1])
    else:
        if(x>=int(k[1])):
            x = x - int(k[1])
        else:
            c = c+1
print(x,c)
