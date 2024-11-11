x=int(input())
y=list(map(int,input().split()))
z=list(map(int,input().split()))
f=0
for i in range(z[0],z[1]):f+=y[i-1]
print(f)

