n, m, k = map(int, input().split())
import math
if m <= math.ceil(n*(k-1)/k):
	print(m)
	exit(0)
ans = math.ceil(n*(k-1)/k)
over = m - ans
N = 1000000009; 
      
# Function code  
def exponentiation(bas, exp): 
    if (exp == 0): 
        return 1; 
    if (exp == 1): 
        return bas % N; 
      
    t = exponentiation(bas, int(exp / 2)); 
    t = (t * t) % N; 
      
    # if exponent is 
    # even value 
    if (exp % 2 == 0): 
        return t; 
          
    # if exponent is 
    # odd value 
    else: 
        return ((bas % N) * t) % N; 
print((ans + ((exponentiation(2, over+1)-2)*k - over*(k-1))) % N)
