n = int(input())

memory = [1]

for i in range(2, n+1):
  memory.append(memory[i-2]+(i-1)*4)

print(memory[n-1])