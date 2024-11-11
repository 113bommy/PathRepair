from sys import stdin
n,m=map(int,stdin.readline().strip().split())
x=n-m
x=x//2
s=""
y=0
if m==1:
    print("0"+(n-1)*"1")
    exit(0)
while len(s)<n:
    if y==1:
        s+="1"*x
    else:
        s+="0"
    y+=1
    y=y%2
    
print(s[0:n])
