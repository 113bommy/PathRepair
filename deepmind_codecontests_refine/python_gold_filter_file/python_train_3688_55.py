n = int(input())

entrada = input().split()

a, b = map(int, input().split())

tempo = 0

for i in range(a-1,b-1):
    tempo += int(entrada[i])

print(tempo)

# 1511873335483
