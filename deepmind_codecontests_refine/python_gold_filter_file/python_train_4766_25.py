X,Y=map(int, input().split())
if Y%2==0 and 4*X>=Y>=2*X:
    print("Yes")
else:
    print("No")
