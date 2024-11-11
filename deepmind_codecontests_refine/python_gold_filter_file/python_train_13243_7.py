import math
import sys
def listIntInput(): return list(map(int,input().split(' ')))
def listStrInput(): return input().split(' ')

def main():
    answer = 0
    n,k = listIntInput()
    cards = []
    three = set(["S","E","T"])
    good_cards = []
    for _ in range(n):
        cards.append(input())
        pass
    for i in range(n):
        for j in range(i+1,n):
            good_card = ""
            for letter in range(k):
                if cards[i][letter] == cards[j][letter]:
                    good_card+= cards[i][letter]
                else:
                    if "S" in [cards[i][letter],cards[j][letter]]:
                        if "E" in [cards[i][letter], cards[j][letter]]:
                            good_card += "T"
                        else:
                            good_card += "E"
                    else:
                        good_card += "S"
                
            good_cards.append(good_card)
    #print(good_cards)

    appearances = dict()
    for card in cards:
        if appearances.get(card, None) == None:
            appearances[card] = 1
        else:
            appearances[card] += 1

    for gc in good_cards:
        answer += appearances.get(gc,0)
                
    
    print(answer//3)

main()
    
