n=int(input())
cards = [(mark,num) for mark in ['S','H','C','D'] for num in range(1,14) ]
for _ in range(n):
    mark,num=input().split()
    cards.remove((mark,int(num)))
for (mark, num) in cards:
    print(mark, num)
