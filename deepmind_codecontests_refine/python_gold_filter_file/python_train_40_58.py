arr=[0]*2
 
arr=list(map(int, input().split()))
 
a=arr[0]
b=arr[1]
h = a
 
while a >= b:
 
    d = int(a / b)
    h += d
    m = a % b
    a = d + m
 
 
print(h)