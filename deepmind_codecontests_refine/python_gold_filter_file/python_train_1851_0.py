count=0
N,D=map(int,input().split())
for i in range(N):
    X,Y=map(int,input().split())
    if D**2>=X**2+Y**2:
        count+=1
print(count)