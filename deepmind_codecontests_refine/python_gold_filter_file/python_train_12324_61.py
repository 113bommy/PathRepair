num = int(input())
 
operations = []
value = 0
for i in range(num):
  expression = input('')
  operations.append(expression)

for j in operations:
  if j == '++X' or j == 'X++' or j == '+X+':
    value += 1
  elif j == '--X' or j == 'X--' or j == '-X-':
    value -= 1

print(value)