# http://codeforces.com/problemset/problem/467/A

# Input
# The first line contains a single integer n (1 ≤ n ≤ 100) — the number of rooms.
n = int(input())
# The i-th of the next n lines contains two integers pi and qi (0 ≤ pi ≤ qi ≤ 100) — the number of people who already live in the i-th room and the room's capacity.

number_of_rooms_where_george_and_alex_can_move_in = 0
# number_of_people_who_already_live_in_the_i_th_room = []
# room_capacity = []
for i in range(0,n):
    pi, qi = list(map(int, input().split(' ')))
    # number_of_people_who_already_live_in_the_i_th_room.append(pi)
    # room_capacity.append(qi)

    # count how many rooms has free place for both George and Alex
    if qi - pi >= 2:
        number_of_rooms_where_george_and_alex_can_move_in += 1

# Output
# Print a single integer — the number of rooms where George and Alex can move in.
print(number_of_rooms_where_george_and_alex_can_move_in)
