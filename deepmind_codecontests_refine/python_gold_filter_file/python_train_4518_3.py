import sys
a,b,n = map(int,input().split())
 
for i in range(-1000,1001):
    if a*(i**n)== b:
        print(i)
        sys.exit()
print("No solution")