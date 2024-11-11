n = int(input())
x, y = 1, n
for i in range(1, int(n**0.5)+1):
        if n%i==0: x = i
y = n//x
print(x+y-2)