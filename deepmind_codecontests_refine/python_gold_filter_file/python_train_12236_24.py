# Andre Victor de Andrade Lopes
# UFCG - AA

n,a,b = map(int, input().split(' '))
result = a + (b%n)
if (result > n):
	result = (result %n) 
print(result)
