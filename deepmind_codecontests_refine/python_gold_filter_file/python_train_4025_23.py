h, m = [int(x) for x in input().split()]
H, D, C, N = [int(x) for x in input().split()]

current_time = h * 60 + m
current_buns = H//N
if H%N != 0:
    current_buns += 1
if current_time > 1200:
    print(current_buns * C * 0.8)
else:
    later_hunger = H + D * (1200-current_time)
    later_buns = later_hunger//N
    if later_hunger%N != 0:
        later_buns += 1
    current_money = current_buns * C
    later_money = later_buns * C * 0.8
    if later_money > current_money:
        print(current_money)
    else:
        print(later_money)

