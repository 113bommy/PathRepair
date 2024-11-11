num = int(input())
if(num%2==0):
    print(((num//2)+1)**2)
else:
    n = num//2+2
    print(n*(n-1)*2)