import math
n= int(input()) 
x = list(map(int, input().split()))
y = sum(x)*1.0/n
z =round(y)

print(sum([(i-z)**2 for i in x]))
