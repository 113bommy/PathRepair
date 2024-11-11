T = int(input())
for t in range(T):
    a, b = [int(x) for x in input().split()]
    mines = input()
    price = 0
    last = ""
    not_mines = []
    there_was_mines = False
    not_mine = 0
    for c in mines:
        if c == '1':
            if last != c:
                price += a
                if not_mine > 0:
                    if there_was_mines:
                        not_mines.append(not_mine)
                    not_mine = 0
            there_was_mines = True
        else:
            not_mine += 1
        last = c
    # print(not_mines)
    for m in not_mines:
        if m*b < a:
            price = price - a + m*b
        
                
                

    print(price)