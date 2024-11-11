n=int(input())
res=0
for i in range(n):
    s=input()
    if s=="++X" or s=="X++":
        res=res+1
    else:
        res=res-1
print(res)