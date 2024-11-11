n = int(input())
h = 0
while n >= (h+1)*(h+2)/2:
    h +=1
    n -= h*(h+1)/2
print(h)
