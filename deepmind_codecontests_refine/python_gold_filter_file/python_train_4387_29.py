# Je déteste que j'aime que je déteste

c = input()
cards = list(map(str, input().split()))
r = False
for card in cards:
    if card[0] == c[0] or card[1] == c[1]:
        r = True
        break
print('YNEOS'[not r::2])