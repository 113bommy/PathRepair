n=int(input())
k=0
for i in range(n+1):
    if i%3!=0 and i%5!=0:
        k=k+i
print(k)

