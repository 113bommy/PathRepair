numbers = '13579'
vowels = 'aeiou'
count = 0
cards = input()
for card in cards:
    if card in vowels or card in numbers:
        count += 1
print(count)
