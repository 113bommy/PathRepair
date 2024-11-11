#coding:utf-8
#1_6_C
def partition(A, p, r):
    x = int(A[r][1])
    i = p - 1
    for j in range(p, r):
        if int(A[j][1]) <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1

def quick_sort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quick_sort(A, p, q - 1)
        quick_sort(A, q + 1, r)
    return A

class CheckStable:
    def __init__(self):
        self.d = dict() # Key is number. Value is array of suit.

    def store_cards(self, cards):
        for i in range(n):
            if cards[i][1] in self.d:
                self.d[cards[i][1]].append(cards[i][0])
            else:
                self.d[cards[i][1]] = [cards[i][0]]

    def is_stable(self, cards):
        for item in reversed(cards):
            if self.d[item[1]].pop() != item[0]:
                return "Not stable"
        return "Stable"

n = int(input())
cards = [tuple(input().split()) for i in range(n)]
d = CheckStable()
d.store_cards(cards)

quick_sort(cards, 0, n - 1)

print(d.is_stable(cards))
for i in range(n):
    print(' '.join(cards[i]))