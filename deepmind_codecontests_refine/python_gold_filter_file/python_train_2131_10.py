def p(x):
    if '8' in x:
        return True

n=str(input())

for i in range(1,17):
    if(p(str(int(n)+i))==True):
        print(i)
        break
