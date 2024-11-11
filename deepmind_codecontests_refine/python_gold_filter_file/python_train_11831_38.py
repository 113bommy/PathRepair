cards = input()
vowels = "aeiou13579"
total = 0
for c in cards: 
    if c in vowels:
        total += 1
print(total)
