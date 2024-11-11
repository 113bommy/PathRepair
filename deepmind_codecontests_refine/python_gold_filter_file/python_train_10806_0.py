n=input()
v=list(map(int, input().split()))
c=list(map(int, input().split()))
t=[i-j if i-j>0 else 0 for i,j in zip(v,c)]
print(sum(t))