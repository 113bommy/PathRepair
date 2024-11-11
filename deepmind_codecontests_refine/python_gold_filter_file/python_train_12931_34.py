inp = input().split(" ")
symbols = [input().split(" ") for i in range(2)] 
n = int(input())
inputs = [int(input()) for i in range(n)]

# print(symbols[0][inputs[0] % len(symbols[0]) - 1])

res = []

for i in range(len(inputs)):
	res.append(symbols[0][inputs[i] % len(symbols[0]) - 1] + symbols[1][inputs[i] % len(symbols[1]) - 1])

print("\n".join(res))