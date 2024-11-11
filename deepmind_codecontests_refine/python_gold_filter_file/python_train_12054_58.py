n=int(input())

t=0
for i in range(n+1):
    if i%3!=0 and i%5!=0:
        t+=i
print(t)