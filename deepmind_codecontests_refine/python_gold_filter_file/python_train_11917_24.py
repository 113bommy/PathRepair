n=int(input())
i=n
while i*(i+1)*(i+2)/6>n:
    i-=1
print(i)
