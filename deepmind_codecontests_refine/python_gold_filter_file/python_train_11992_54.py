if __name__ == '__main__':
    n = int(input())
    txt = input()
    dct = {'z': 0, 'e': 0, 'r': 0, 'o': 0, 'n': 0}
    for i in list(txt):
        dct[i] += 1
    ones = min([dct['o'], dct['n'], dct['e']])
    dct['o'] -= ones
    dct['n'] -= ones
    dct['e'] -= ones
    zeroes = min([dct['o'], dct['z'], dct['e'], dct['r']])
    res = ['1 ' for i in range(ones)] + ['0 ' for i in range(zeroes)]
    
    print("".join(res))
