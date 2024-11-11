a=input().split(" ")
b=input().split(" ")
b=list(map(int,b))
b=sorted(b)
min=int(b[int(a[0])-1]-int(b[0]))
for i in range(int(a[1])-int(a[0])+1):
    if min>int(b[int(a[0])+i-1]-b[i]):
        min=int(b[int(a[0])+i-1]-b[i])
print(min)