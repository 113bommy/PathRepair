from operator import sub

def wins(next_tern):
    return ((left_X(next_tern) and right_X(next_tern))
        or (up_X(next_tern) and below_X(next_tern))
        or (left_below_X(next_tern) and right_up_X(next_tern))
        or (left_up_X(next_tern) and right_below_X(next_tern))
        or right_right(next_tern) or left_left(next_tern)
        or up_up(next_tern) or below_below(next_tern)
        or ulul(next_tern) or urur(next_tern)
        or blbl(next_tern) or brbr(next_tern))

def ulul(next_tern):
    return left_up_X(next_tern) and has_X(2, 2, next_tern)

def urur(next_tern):
    return right_up_X(next_tern) and has_X(2, -2, next_tern)

def blbl(next_tern):
    return left_below_X(next_tern) and has_X(-2, 2, next_tern)

def brbr(next_tern):
    return right_below_X(next_tern) and has_X(-2, -2, next_tern)


def right_right(next_tern):
    return right_X(next_tern) and has_X(0, -2, next_tern)

def left_left(next_tern):
    return left_X(next_tern) and has_X(0, 2, next_tern)

def up_up(next_tern):
    return up_X(next_tern) and has_X(2, 0, next_tern)

def below_below(next_tern):
    return below_X(next_tern) and has_X(-2, 0, next_tern)



def left_X(next_tern):
    return has_X(0, 1, next_tern)

def up_X(next_tern):
    return has_X(1, 0, next_tern)

def right_X(next_tern):
    return has_X(0, -1, next_tern)

def below_X(next_tern):
    return has_X(-1, 0, next_tern)

def left_below_X(next_tern):
    return has_X(-1, 1, next_tern)

def right_up_X(next_tern):
    return has_X(1, -1, next_tern)

def right_below_X(next_tern):
    return has_X(-1, -1, next_tern)

def left_up_X(next_tern):
    return has_X(1, 1, next_tern)

def has_X(a, b, next_tern):
    a = next_tern[0] - a
    b = next_tern[1] - b
    return (a in range(4) and b in range(4) and layout[a][b] == 1)

layout = [[] for i in range(4)]

for i in range(4):
    ch = input()
    for j in range(4):
        if ch[j] == 'o':
            layout[i].append(2)
        elif ch[j] == 'x':
            layout[i].append(1)
        else:
            layout[i].append(0)

for i in range(4):
    for j in range(4):
        if layout[i][j] == 0 and wins((i, j)):
            #print(i, j)
            print("YES")
            exit()
print("NO")



