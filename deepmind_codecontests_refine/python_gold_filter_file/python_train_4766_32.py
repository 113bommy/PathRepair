
X,Y = map(int, input().split())
if Y%2==0 and Y<=4*X and Y>=2*X:
    print("Yes")
else:
    print("No")