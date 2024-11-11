n=int(input())
if n<3:
    print("No")
    exit()
a=[]
b=[]
for i in range(1,n+1):
    if i&1:
        a.append(i)
    else:
        b.append(i)
print("Yes")
print(len(a),end=" ")
print(*a)
print(len(b),end=" ")
print(*b)