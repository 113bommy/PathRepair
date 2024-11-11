point_list = [('Q', 9), ('R', 5), ('B', 3), ('N', 3), ('P', 1)];
point_list = point_list + list(map(lambda x: (x[0].lower(), -x[1]), point_list));
# print(point_list);

point_dict = dict(point_list);

points = 0;
try:
    while True:
        line = input();
        points += sum(map(lambda c: point_dict[c] if c in point_dict else 0, line));
except EOFError:
    pass
    
if points == 0:
    print('Draw');
elif points > 0:
    print('White');
else:
    print('Black');


