if __name__ == '__main__':
    n, m = 0, 0
    for i in input():
        if i == 'o':
            n += 1
        else:
            m+=1
    if n ==0:
        print("YES")
    elif m%n==0:
        print("YES")
    else:
        print("NO")