n=int(input())
x=(n//210)*48
for i in range(n%210+1):
    if (i %2 != 0)and(i %3 != 0)and (i %5 != 0)and(i %7 != 0):
        x+=1
print(x)
