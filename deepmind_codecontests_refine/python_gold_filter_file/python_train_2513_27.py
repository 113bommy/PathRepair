n=int(input())
a=[int(x) for x in input()]
suma=0
for i in range(n):
    if a[i]%2 != 0:
        suma=suma+(i+1)    
print(int(((n*(n+1))/2)-suma))