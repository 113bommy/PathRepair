n = int(input())
if n%2==0 or  n<5:
    print("NO")
else:
    d= n-1
    print(1,d//2 - 1)
