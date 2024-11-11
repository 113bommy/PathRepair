# @author Matheus Alves dos Santos

from collections import defaultdict

flips_needed = defaultdict(lambda: 0, {
    'a': 1, 'e': 1, 'i': 1, 'o': 1, 'u': 1,
    '1': 1, '3': 1, '5': 1, '7': 1, '9': 1,
})

card_values = input()
flips = 0

for v in card_values:
    flips += flips_needed[v]
    
print(flips)
