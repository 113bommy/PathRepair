def f1():
    x = str(input())
    i = 0
    numero = int(x,2)
    while True:
        if pow(4,i) >= numero:
            return(i)
            break
        else:
            i +=1

print(f1())
