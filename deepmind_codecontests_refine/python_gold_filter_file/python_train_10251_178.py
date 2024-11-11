n = int(input())
s = 0
if(n % 2 == 0):
    s = n//2
else:
    s = -(n+1)//2

print(s)