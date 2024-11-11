r,g,b=list(map(int,input().split()))
r=r//2+r%2
g=g//2+g%2
b=b//2+b%2
r=(r-1)*3+30
g=(g-1)*3+31
b=(b-1)*3+32
print(max(r,b,g))
