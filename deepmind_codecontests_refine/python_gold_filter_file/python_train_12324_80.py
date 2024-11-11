n=int(input())
k=0
for i in range(n):
    x=input()
    if x=="++X" or x=="X++":
        k+=1
    else:
        k-=1
print(k)