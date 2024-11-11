n = int(input())

def iflucky(n):
    k = str(n)
    for i in k:
        if i == '8':
            return True
    else:
        return False

count = 1
while True:
    n+=1


    z = iflucky(n)
    if z is True:
        print(count)
        break
    else:
        count+=1



