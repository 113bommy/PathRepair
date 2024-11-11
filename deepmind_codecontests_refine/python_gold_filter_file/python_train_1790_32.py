q = int(input())
i = 0

while i<q:
    n = int(input())
    if n>=4:
        c = n//2
        print(n-2*c)
    else:
        print(4-n)
    i+=1
