def process(n):
    a=n*(n+1)//2
    if a%2==0:
        return 0
    else:
        return 1
n=int(input())
print(process(n))