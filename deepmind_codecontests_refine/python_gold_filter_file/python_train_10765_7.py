n=list(reversed(list(input())))
for c in n:
    x=int(c)
    if x>=5:
        print('-O|',end="")
        print('O'*(x-5)+'-'+'O'*(9-x))
    else:
        print('O-|'+'O'*(x)+'-'+'O'*(4-x))
        