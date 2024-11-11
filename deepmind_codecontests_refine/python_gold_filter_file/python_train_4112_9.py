n = int(input())
l = len(str(n))
count = 0
x = 1
y = 1
if l == 1:
    print(n)
else:
    for i in range(len(str(n))-1):
        count += 9 * x * y
        x *= 10
        y += 1  
    print(count + l*(n - (10**(l-1)) +1))                 
      
