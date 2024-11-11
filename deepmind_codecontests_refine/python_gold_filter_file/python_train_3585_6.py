n=int(input())
a=list(input())
X=a.count("X")
x=n-X
print(abs(n//2-X))
if X>x:
    c=abs(n//2-X)
    for i in range(n):
        if c==0:
            break
        if a[i]=="X":
            a[i]="x"
            c-=1
else:
    c = abs(n // 2 - X)
    for i in range(n):
        if c==0:
            break
        if a[i] == "x":
            a[i] = "X"
            c -= 1
print("".join(a))