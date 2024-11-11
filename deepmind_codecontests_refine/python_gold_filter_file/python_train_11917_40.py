n=int(input())
if n == 1:
    print(1)
else:
    i=1
    s=1
    while n>=s:
        i+=1
        s+=i*(i+1)/2
    print(i-1)
