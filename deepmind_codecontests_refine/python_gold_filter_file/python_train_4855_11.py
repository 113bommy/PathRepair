beautiful = []
for i in range(1, 10):
  beautiful.append((2**i - 1)*2**(i-1))
  
n = int(input())

largest = 1
for i in beautiful:
  if n%i == 0:
    largest = i
    
print(largest)
