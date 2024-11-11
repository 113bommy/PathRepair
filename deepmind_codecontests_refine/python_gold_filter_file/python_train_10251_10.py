n=int(input())
if n%2==0:
    print(n//2)
else:
    prev=(n-1)//2
    print(prev-n)