t = int(input())

def solve():
    case = input()
    sep = []
    temp = ''
    indices = []
    for i in case:
        if(i == '0'):
            if(temp != ''):
                sep.append(temp)
                temp = ''
                indices.append(len(sep) - 1)
                sep.append(i)
            else:
                sep.append(i)
        else:
            temp += '1'


    if(temp != ''):
        sep.append(temp)
        indices.append(len(sep) - 1)
    count = 0
    for i in range(1, len(indices)):
        count += indices[i] - indices[i - 1] - 1
    print(count)


for i in range(t):
    solve()
