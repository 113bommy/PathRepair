def calculator(a,b):
    if a == "rock":
        if b == "rock":
            return '?'
        elif b == "paper":
            return '2'
        else:
            return '1'

    elif a == "paper":
        if b == "rock":
            return '1'
        elif b == "paper":
            return '?'
        else:
            return '2'
    else:
        if b == "rock":
            return '2'
        elif b == "paper":
            return '1'
        else:
            return '?'
i = input
F=i()
M=i()
S=i()
print('F' if (calculator(F,M)=='1' and calculator(F,S)=='1') else 'M' if (calculator(M,F)=='1' and calculator(M,S)=='1') else 'S' if calculator(S,F)=='1' and calculator(S,M)=='1' else '?')


