n=int(input())
i=0
while i*(i+1)*(i+2)/6 <= n:
    i=i+1
print(i-1)
