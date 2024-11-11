import sys

cards = sys.stdin.readline().strip()

cards_flipped = sum([1 if c in 'aeiou13579' else 0 for c in cards])

print(cards_flipped)
