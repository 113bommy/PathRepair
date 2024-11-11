a = input()
b = "13579aeiou"

k = 0

for s in a:
    if s in b:
        k += 1
        
print(k)