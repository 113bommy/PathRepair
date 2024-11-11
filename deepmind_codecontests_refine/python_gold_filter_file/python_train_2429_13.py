n=int(input())
pat=input()
a=[]
b=[]
for i in range(n):
    a.append(int(pat[i]))
for i in range(n):
    l = i + n
    b.append(int(pat[l]))
a.sort()
b.sort()
k=0
if a[0] > b[0]:
    for i in range(n):
        if a[i]<=b[i]:
            print("NO")
            k=-1
            break
elif a[0] < b[0]:
    for i in range(n):
        if a[i] >= b[i]:
            print("NO")
            k = +1
            break
else:
    print("NO")
    k=-5
if k==0: print("YES")
