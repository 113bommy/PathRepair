from collections import deque 

number_of_lines = 0
lines = []
type_of_lines = deque([])
times = deque([])
result = 0
printed = False


def Input(number_of_lines,lines):
    number_of_lines = int(input())

    for index in range(number_of_lines):
        lines.append(list(map(str,input().split())))

    return number_of_lines,lines

def Processing(number_of_lines,lines,result,type_of_lines, times, printed):

    for index in range(number_of_lines):
        if len(lines[index]) == 2:
            type_of_lines.append(int(lines[index][1]))
        else: 
            if lines[index][0] == 'add':
                type_of_lines.append(-1)
            else:
                type_of_lines.append(0)


    index = 0;
    tem = 0
    # result of one loop = count*multi
    while type_of_lines:
        type_line = type_of_lines[0]

        if type_line != 0:
            times.append(type_line)
        else:
            count = 0
            while times[-1] < 0:
                count -= times[-1]
                times.pop()

            tem = count*times[-1]
            times.pop()

            if tem != 0:
                times.append(-tem)

            if (tem) > 2**32 - 1:
                print('OVERFLOW!!!')
                printed = True
                return number_of_lines,lines, result, type_of_lines, times, printed


        type_of_lines.popleft()

    return number_of_lines,lines, result, type_of_lines, times, printed

def Output(times, printed):
    
    result = 0
    result = abs(sum(times)) 

    if printed == False:
        if result <= 2**32 -1 :
            print(result)
        else:
            print('OVERFLOW!!!')

    return times, printed

if __name__ == '__main__':
    number_of_lines,lines = Input(number_of_lines,lines)
    number_of_lines,lines,result, type_of_lines, times, printed = Processing(number_of_lines,lines,result, type_of_lines, times, printed)
    times, printed = Output(times,printed)