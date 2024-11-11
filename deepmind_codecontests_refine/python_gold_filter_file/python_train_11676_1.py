n = int(input()) 

def f(n):
    n += 1
    flag = False
    while flag == False:
        if n % 10 == 0:
            n = n//10
        else:
            flag = True
    return n        

count = 1
store = [n]
while n > 0:
    if f(n) in store:
        n = 0
        print(count)
    else:
        store.append(f(n))
        count += 1
        n = f(n)